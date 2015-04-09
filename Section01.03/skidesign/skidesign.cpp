/*
ID: gespo891
PROG: skidesign
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");

    int n, min_cost = 10000000, min_hill, max_hill;
    vector<int> hills;
    fin >> n;
    for(int i = 0; i < n; i++){
        int hill;
        fin >> hill;
        hills.push_back(hill);
    }
    sort(hills.begin(), hills.end());
    min_hill = *hills.begin();
    max_hill = *(hills.end() - 1);
    for(int i = min_hill; i < max_hill; i++){
        int cost = 0;
        for(auto hill : hills){
            if(hill < i){
                cost += pow(i - hill, 2);
            } else if (hill > i + 17){
                cost += pow(hill - i - 17, 2);
            }
        }
        min_cost = min(cost, min_cost);
    }

    fout << min_cost << endl;
    fin.close();
    fout.close();
    return 0;
}