/*
ID: gespo891
PROG: dualpal
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

char symbols[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string num_in_base(int, int);

bool is_palindrome(string const &);

int main() {
    ifstream fin ("dualpal.in");
    ofstream fout ("dualpal.out");

    vector<int> results;
    int n, s;
    fin >> n >> s;
    while(results.size() < n){
        s++;
        int numpals = 0;
        for(int i = 2; i <= 10 && numpals < 2; i++){
            if(is_palindrome(num_in_base(s, i))){
                numpals++;
            }
        }
        if(numpals == 2) {
            results.push_back(s);
        }
    }
    sort(results.begin(), results.end());
    for(auto val: results){
        fout << val << endl;
    }
    fin.close();
    fout.close();
    return 0;
}

string num_in_base(int value, int base){
    string output;
    while(value > 0){
        output += symbols[value % base];
        value /= base;
    }
    reverse(output.begin(), output.end());
    return output;
}

bool is_palindrome(string const &s){
    for(auto left = s.cbegin(), right = --s.cend(); right > left; left++, right--){
        if(*left != *right){
            return false;
        }
    }
    return true;
}