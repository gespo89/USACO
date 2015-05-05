/*
ID: gespo891
PROG: nocows
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[201][101];
int N, K, ops = 0;

int solve(int n, int k){
    ops++;
    if(dp[n][k] != -1) {
        return dp[n][k];
    }
    n;
    int sum = 0;
    if(k > (n - 1)/2 + 1 || log2(n) >= k) return 0;

    for(int i = 1; i < n - 1; i+= 2){
        for(int j = 1; j < k; j++){
            int count = solve(i, k - 1) * solve(n - 1 - i, j);
            sum += count;
            if(k - 1 != j){
                sum += count;
            }
            sum %= 9901;
        }
    }
    return dp[n][k] = sum;
}

int main() {
    ifstream fin ("nocows.in");
    ofstream fout ("nocows.out");

    fin >> N >> K;
    for(int n = 0; n <= N; n++){
        for(int k = 0; k <= K; k++) {
            if (n == 1)
                dp[n][k] = 0;
            else dp[n][k] = -1;
        }
    }
    dp[1][1] = 1;
    fout << solve(N, K) << endl;

    cout << ops << endl;
    fin.close();
    fout.close();
    return 0;
}