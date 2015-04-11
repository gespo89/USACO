/*
ID: gespo891
PROG: numtri
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin ("numtri.in");
    ofstream fout ("numtri.out");

    int n;
    fin >> n;
    vector<vector<int>> levels;
    for(int i = 1; i <= n; i++){
        vector<int> level;
        for(int j = 0; j < i; j++){
            int num;
            fin >> num;
            level.push_back(num);
        }
        levels.push_back(level);
    }


    for(int i = n - 1; i > 0; i--){
        for(int j = 0; j < levels[i - 1].size(); j++){
            levels[i - 1][j] += max(levels[i][j], levels[i][j + 1]);
        }
    }

    fout << levels[0][0];
    fin.close();
    fout.close();
    return 0;
}