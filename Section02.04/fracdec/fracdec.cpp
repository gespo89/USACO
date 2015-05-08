/*
ID: gespo891
PROG: fracdec
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

int N, D;
queue<pair<int, int>> digits;
set<int> seen;
int numdigits, repeat = -1;

int main() {
    ifstream fin ("fracdec.in");
    ofstream fout ("fracdec.out");

    fin >> N >> D;

    numdigits = 2;
    if(N > D)
        numdigits = log10((double)(N/D)) + 2;
    fout << (N / D) << ".";
    int remainder = N % D;
    if(!remainder) fout << "0";
    while(remainder){
        int old = remainder;
        if(!seen.insert(remainder).second){
            repeat = remainder;
            break;
        }
        remainder *= 10;
        digits.push(pair<int, int>{old, remainder/D});
        remainder %= D;
    }

    while(!digits.empty()){
        if(digits.front().first == repeat){
            fout << "(";
            numdigits = (numdigits + 1) % 76;
            if(!numdigits)
                fout << endl;
        }
        fout << digits.front().second;
        digits.pop();
        numdigits = (numdigits + 1) % 76;
        if(!numdigits)
            fout << endl;
    }
    if(repeat != -1){
        numdigits++;
        fout << ")";
    }
    if(numdigits)
        fout << endl;

    fin.close();
    fout.close();
    return 0;
}