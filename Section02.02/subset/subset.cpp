/*
ID: gespo891
PROG: subset
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int N;
vector<vector<int64_t>> dp;

int64_t solve(int k, int n){
    if(k < 0 || n < 0){
        return 0;
    }
    if(k == 0 && n == 0){
        return 1;
    }
    if(dp[k][n] >= 0){
        return dp[k][n];
    }
    return dp[k][n] = solve(k, n - 1) + solve(k - n, n - 1);
}

int main() {
    ifstream fin ("subset.in");
    ofstream fout ("subset.out");

    fin >> N;
    int sum = N * (N + 1) / 2;
    if(sum %2) {
        fout << 0 << endl;
    } else {
        for(int i = 0; i <= sum/2; i++){
            dp.push_back(vector<int64_t>(N + 1, -1));
        }
        fout << solve(sum / 2, N) / 2 << endl;
    }

    fin.close();
    fout.close();
    return 0;
}