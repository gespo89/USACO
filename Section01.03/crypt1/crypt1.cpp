/*
ID: gespo891
PROG: crypt1
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

bool is_cryptarithm (int, int, vector<int> const &);

int digit (int, int);

int main() {
    ifstream fin ("crypt1.in");
    ofstream fout ("crypt1.out");
    int n, count = 0;
    vector<int> digits;
    fin >> n;
    for(int i = 0; i < n; i++){
        int digit;
        fin >> digit;
        digits.push_back(digit);
    }

    for(int i = 0; i < digits.size(); i++){
        for(int j = 0; j < digits.size(); j++){
            for(int k = 0; k < digits.size(); k++){
                for(int l = 0; l < digits.size(); l++){
                    for(int m = 0; m < digits.size(); m++){
                        int a = digits[i] * 100 + digits[j] * 10 + digits[k];
                        int b = digits[l] * 10 + digits[m];
                        if(is_cryptarithm(a, b, digits)){
                            count++;
                        }
                    }
                }
            }
        }
    }

    fout << count << endl;
    fin.close();
    fout.close();
    return 0;
}

bool is_cryptarithm (int a, int b, vector<int> const & digits){
    int c = digit(b, 0) * a;
    int d = digit(b, 1) * a;
    int e = a * b;

    if(c < 100 || c > 999){
        return false;
    }
    for(int i = 0; i < 3; i++){
        if(find(digits.begin(), digits.end(), digit(c, i)) == digits.end()){
            return false;
        }
    }
    if(d < 100 || d > 999){
        return false;
    }
    for(int i = 0; i < 3; i++){
        if(find(digits.begin(), digits.end(), digit(d, i)) == digits.end()){
            return false;
        }
    }
    if(e < 1000 || e > 9999){
        return false;
    }
    for(int i = 0; i < 4; i++){
        if(find(digits.begin(), digits.end(), digit(e, i)) == digits.end()){
            return false;
        }
    }
    return true;

}

int digit(int number, int index){
    return (number / (int)pow(10, index)) % 10;
}