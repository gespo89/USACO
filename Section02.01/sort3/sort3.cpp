/*
ID: gespo891
PROG: sort3
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int N, counts[4][4];

int main() {
    ifstream fin ("sort3.in");
    ofstream fout ("sort3.out");

    fin >> N;

    vector<int> nums;
    for(int i = 0; i < N; i++){
        int num;
        fin >> num;
        nums.push_back(num);
    }
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < nums.size(); i++){
        counts[nums[i]][sorted[i]]++;
    }

    int total = 0;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 3; j++){
            if(i == j){
                counts[i][j] = 0;
            } else {
                int swaps = min(counts[i][j], counts[j][i]);
                counts[i][j] -= swaps;
                counts[j][i] -= swaps;
                total += swaps;
            }
        }
    }
    int remaining = 0;
    for(int i = 1; i<= 3; i++){
        for(int j = 1; j <= 3; j++){
            remaining += counts[i][j];
        }
    }

    total += remaining / 3 * 2;

    fout << total << endl;

    fin.close();
    fout.close();
    return 0;
}