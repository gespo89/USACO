/*
ID: gespo891
PROG: zerosum
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N;
char ops[10];
vector<string> solutions;

void check(){
    string s = "1";
    int current = 1;
    int total = 0;
    int sign = '+';
    for(int i = 1; i < N; i++){
        if(ops[i-1] == ' '){
            current *= 10;
            current += i + 1;
            s += ' ';
        } else if(ops[i-1] == '+'){
            if(sign == '+')
                total += current;
            else
                total -= current;
            current = i + 1;
            sign = '+';
            s += '+';
        } else if(ops[i-1] == '-'){
            if(sign == '+')
                total += current;
            else
                total -= current;
            current = i + 1;
            sign = '-';
            s += '-';
        }
        s += i + '1';
    }
    if(sign == '+')
        total += current;
    else
        total -= current;
    if(total == 0)
        solutions.push_back(s);
}

void solve(int i){
    if(i == N - 1) {
        check();
        return;
    }
    ops[i] = ' ';
    solve(i+1);
    ops[i] = '+';
    solve(i+1);
    ops[i] = '-';
    solve(i+1);
}

int main() {
    ifstream fin ("zerosum.in");
    ofstream fout ("zerosum.out");
    fin >> N;
    solve(0);
    for(auto s: solutions){
        fout << s << endl;
    }
    fin.close();
    fout.close();
    return 0;
}