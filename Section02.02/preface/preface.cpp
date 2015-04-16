/*
ID: gespo891
PROG: preface
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N, counts[26];

void ones(int n){
    n %= 10;
    if(n <= 3){
        counts['I' - 'A'] += n;
    } else if (n == 4){
        counts['I' - 'A']++;
        counts['V' - 'A']++;
    } else if (n < 9) {
        counts['V' - 'A']++;
        counts['I' - 'A']+= (n - 5);
    } else {
        counts['I' - 'A']++;
        counts['X' - 'A']++;
    }
}

void tens(int n){
    n = (n % 100)/10;
    if(n <= 3){
        counts['X' - 'A'] += n;
    } else if (n == 4){
        counts['X' - 'A']++;
        counts['L' - 'A']++;
    } else if (n < 9) {
        counts['L' - 'A']++;
        counts['X' - 'A']+= (n - 5);
    } else {
        counts['X' - 'A']++;
        counts['C' - 'A']++;
    }
}

void hundreds(int n){
    n = (n % 1000)/100;
    if(n <= 3){
        counts['C' - 'A'] += n;
    } else if (n == 4){
        counts['C' - 'A']++;
        counts['D' - 'A']++;
    } else if (n < 9) {
        counts['D' - 'A']++;
        counts['C' - 'A']+= (n - 5);
    } else {
        counts['C' - 'A']++;
        counts['M' - 'A']++;
    }
}

void thousands(int n){
    counts['M' - 'A'] += n/1000;
}

int main() {
    ifstream fin ("preface.in");
    ofstream fout ("preface.out");
    fin >> N;
    for(int i = 1; i <= N; i++){
        ones(i);
        tens(i);
        hundreds(i);
        thousands(i);
    }
    for(char i: {'I', 'V', 'X', 'L', 'C', 'D', 'M'}){
        int count = counts[i - 'A'];
        if(count){
            fout << i << " " << count << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}