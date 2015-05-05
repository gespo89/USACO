/*
ID: gespo891
PROG: concom
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, control[101][101];

void search(queue<int> & next, map<int, int> & current){
    if(next.empty()) return;
    int c = next.front();
    next.pop();
    for(int i = 0; i <= 100; i++){
        int val = control[c][i];
        current[i] += val;
        if(current [i] > 50 && current[i] - val <= 50){
            next.push(i);
        }
    }
    search(next, current);
}

int main() {
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");
    fin >> N;
    for(int n = 0; n < N; n++){
        int i, j, p;
        fin >> i >> j >> p;
        control[i][j] = p;
        control[i][i] = 100;
        control[j][j] = 100;
    }

    for(int i = 1; i <= 100; i++){
        if(!control[i][i]) continue;
        map<int, int> current;
        queue<int> next;
        for(int j = 0; j <= 100; j++){
            current[j] += control[i][j];
            if(i != j && current[j] > 50)
                next.push(j);
        }
        search(next, current);
        for(int j = 1; j <= 100; j++){
            if(i != j && current[j] > 50){
                fout << i << " " << j << endl;
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}