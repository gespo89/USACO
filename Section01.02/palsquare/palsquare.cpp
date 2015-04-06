/*
ID: gespo891
PROG: palsquare
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

char symbols[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

string num_in_base(unsigned int value, unsigned int);

bool is_palindrome(string);

int main() {
    ifstream fin ("palsquare.in");
    ofstream fout ("palsquare.out");

    unsigned int base;
    fin >> base;

    for(int i = 1; i <= 300; i++){
        string val = num_in_base(pow(i, 2), base);
        if(is_palindrome(val)){
            fout << num_in_base(i, base) << " " << val << endl;
        }
    }

    fin.close();
    fout.close();
    return 0;
}

string num_in_base(unsigned int value, unsigned int base){
    string output;
    while(value > 0){
        output += symbols[value % base];
        value /= base;
    }
    reverse(output.begin(), output.end());
    return output;
}

bool is_palindrome(string s){
    for(auto left = s.begin(), right = --s.end(); right > left; left++, right--){
        if(*left != *right){
            return false;
        }
    }
    return true;
}