/*
ID: gespo891
PROG: combo
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ifstream fin ("combo.in");
    ofstream fout ("combo.out");

    int max, farmer[3], master[3];
    set<vector<int>> combos;
    fin >> max;
    fin >> farmer[0] >> farmer[1] >> farmer[2];
    fin >> master[0] >> master[1] >> master[2];
    for(int i = 0; i < 3; i++){
        master[i]--;
        farmer[i]--;
    }

    for(int i = -2; i <= 2; i++){
        for(int j = -2; j <= 2; j++){
            for(int k = -2; k <= 2; k++){
                int f1 = (farmer[0] + i) % max;
                int f2 = (farmer[1] + j) % max;
                int f3 = (farmer[2] + k) % max;
                combos.insert(vector<int> {
                    f1 < 0 ? f1 + max : f1,
                    f2 < 0 ? f2 + max : f2,
                    f3 < 0 ? f3 + max : f3
                });
                int m1 = (master[0] + i) % max;
                int m2 = (master[1] + j) % max;
                int m3 = (master[2] + k) % max;
                combos.insert(vector<int> {
                    m1 < 0 ? m1 + max : m1,
                    m2 < 0 ? m2 + max : m2,
                    m3 < 0 ? m3 + max : m3
                });
            }
        }
    }

    fout << combos.size() << endl;

    fin.close();
    fout.close();
    return 0;
}