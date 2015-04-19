/*
ID: gespo891
PROG: money
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int V, N;
vector<int> coins;
vector<vector<long long>> totals;

int main() {
    ifstream fin ("money.in");
    ofstream fout ("money.out");

    fin >> V >> N;
    for(int i = 0; i < V; i++){
        int coin;
        fin >> coin;
        coins.push_back(coin);
    }
    for(int i = 0; i <= N; i++){
        totals.push_back(vector<long long>(V, 0));
    }
    for(int i = 0; i < V; i++){
        totals[0][i] = 1;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < V; j++){
            int coin = coins[j];
            if(i - coin >= 0)
                totals[i][j] += totals[i - coin][j];
            for(int k = j + 1; k < V; k++){
                coin = coins[k];
                if(i - coin > 0)
                    totals[i][k] += totals[i - coin][j];
            }
        }
    }
    long long answer = 0;
    for(auto i: totals[N]){
        answer += i;
    }
    fout << answer << endl;

    fin.close();
    fout.close();
    return 0;
}