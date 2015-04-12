/*
ID: gespo891
PROG: sprime
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N;

void solve(int, ofstream &);
bool is_prime(int);

int main() {
    ifstream fin ("sprime.in");
    ofstream fout ("sprime.out");
    fin >> N;

    for(int i = 2; i < 9; i++) {
        solve(i, fout);
    }

    fin.close();
    fout.close();
    return 0;
}

void solve(int m, ofstream &fout){
    if(!is_prime(m))
        return;
    int length = (int) floor(log10(m) + 1);
    if(length == N){
        fout << m << endl;
        return;
    }
    m *= 10;
    for(int i = 0; i < 9; i++){
        m ++;
        solve(m, fout);
    }
}

bool is_prime(int n){
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0)
            return false;
    return true;
}