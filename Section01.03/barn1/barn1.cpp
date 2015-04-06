/*
ID: gespo891
PROG: barn1
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ifstream fin ("barn1.in");
    ofstream fout ("barn1.out");

    int boards, stalls, cows;
    fin >> boards >> stalls >> cows;
    vector<int> filled;
    for(int i = 0; i < cows; i++){
        int stall;
        fin >> stall;
        filled.push_back(stall);
    }
    sort(filled.begin(), filled.end());
    vector<int> gaps;
    int gap, last = filled[0] - 1, total = 0;
    for(auto index: filled){
        gap = index - last - 1;
        gaps.push_back(gap);
        total += gap;
        last = index;
    }

    sort(gaps.begin(), gaps.end(), greater<int>());
    for(int i = 0; i < boards - 1 && total > 0; i++){
        total -= gaps[i];
    }
    fout << total + cows << endl;

    fin.close();
    fout.close();
    return 0;
}