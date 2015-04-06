/*
ID: gespo891
PROG: milk
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

struct farmer{
    int quantity;
    int price;
};

int main() {
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");
    int quantity, count;
    fin >> quantity >> count;
    vector<farmer> farmers;
    for(int i = 0; i < count; i++){
        farmer f;
        fin >> f.price >> f.quantity;
        farmers.push_back(f);
    }
    sort(farmers.begin(), farmers.end(), [] (farmer const & a, farmer const & b) -> bool{
        return b.price > a.price;
    });
    int i = 0, cost = 0;
    while(quantity > 0){
        farmer &next = farmers[i];
        int buy = min(quantity, next.quantity);
        cost += buy * next.price;
        quantity -= buy;
        i++;
    }
    fout << cost << endl;

    fin.close();
    fout.close();
    return 0;
}