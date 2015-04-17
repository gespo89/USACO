/*
ID: gespo891
PROG: runround
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

bool is_runaround(int n){
    int num_digits = floor(log10(n)) + 1;
    vector<int> digits(num_digits);
    set<int> distinct;
    for(int i = num_digits - 1; i >= 0; i--){
        digits[i] = n % 10;
        distinct.insert(digits[i]);
        n /= 10;
    }
    if(distinct.size() != num_digits)
        return false;
    int index = 0;
    for(int i = 0; i < num_digits; i++){
        if(digits[index] == -1)
            return false;
        int previous = index;
        index = (index + digits[index]) % num_digits;
        digits[previous] = -1;
    }
    return index == 0;
}

int main() {
    ifstream fin ("runround.in");
    ofstream fout ("runround.out");

    int n;
    fin >> n;
    for(n = n + 1; !is_runaround(n); n++);
    fout << n << endl;


    fin.close();
    fout.close();
    return 0;
}