/*
ID: gespo891
PROG: ariprog
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int N, M;
vector<bool> is_bisquare(125001, false);
set<int> bisquares;
vector<pair<int, int>> results;

int main() {
    ifstream fin ("ariprog.in");
    ofstream fout ("ariprog.out");
    fin >> N >> M;
    for(int i = 0; i <= M; i++){
        for(int j = i; j <= M; j++){
            int val = pow(i, 2) + pow(j, 2);
            bisquares.insert(val);
            is_bisquare[val] = true;
        }
    }
    for(auto i = bisquares.begin(); i != bisquares.end(); i++){
        for(auto j = next(i); j != bisquares.end() && (*j - *i) * (N - 2) + *i <= 125000; j++){
            int n = 1;
            for(int k = *j; k <= 125000 && is_bisquare[k]; k += (*j - *i))
                n++;
            if(n >= N){
                results.push_back(pair<int,int>(*i,*j - *i));
            }
        }
    }
    sort(results.begin(), results.end(), [](pair<int, int> a, pair<int, int> b) -> bool{
        if(a.second < b.second){
            return true;
        }
        return a.second == b.second and a.first < b.first;
    });
    if(results.size() == 0){
        fout << "NONE" << endl;
    }
    for(auto p : results){
        fout << p.first << " " << p.second << endl;
    }

    fin.close();
    fout.close();
    return 0;
}