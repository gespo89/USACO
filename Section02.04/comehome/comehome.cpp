/*
ID: gespo891
PROG: comehome
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int N, paths[52][52];
set<int> cows;

int main() {
    ifstream fin ("comehome.in");
    ofstream fout ("comehome.out");
    fin >> N;

    for(int i = 0; i < 52; i++)
        for(int j = 0; j < 52; j++)
            paths[i][j] = 1000000;

    for(int i = 0; i < N; i++){
        char a, b;
        int cost;
        fin >> a >> b >> cost;
        if(a >= 'A' && a <= 'Z') {
            a -= 'A';
            a += 26;
            if(a != 51) cows.insert(a);
        } else {
            a -= 'a';
        }
        if(b >= 'A' && b <= 'Z') {
            b -= 'A';
            b += 26;
            if(b != 51) cows.insert(b);
        } else {
            b -= 'a';
        }
        paths[a][b] = min(paths[a][b], cost);
        paths[b][a] = min(paths[b][a], cost);
    }

    for(int k = 0; k < 52; k++)
        for(int i = 0; i < 52; i++)
            for(int j = 0; j < 52; j++)
                paths[i][j] = min(paths[i][j], paths[i][k] + paths[k][j]);

    int min = 10000000;
    int min_cow = 0;
    for(int i: cows){
        if(paths[i][51] < min){
            min = paths[i][51];
            min_cow = i;
        }
    }

    fout << (char)(min_cow + 'A' - 26) << " " << min << endl;



    fin.close();
    fout.close();
    return 0;
}