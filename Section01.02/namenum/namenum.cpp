/*
ID: gespo891
PROG: namenum
LANG: C++11
*/
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("namenum.in");
    ofstream fout ("namenum.out");
    ifstream names ("dict.txt");

    char nums[256] = {};
    nums['A'] = nums['B'] = nums['C'] = '2';
    nums['D'] = nums['E'] = nums['F'] = '3';
    nums['G'] = nums['H'] = nums['I'] = '4';
    nums['J'] = nums['K'] = nums['L'] = '5';
    nums['M'] = nums['N'] = nums['O'] = '6';
    nums['P'] = nums['R'] = nums['S'] = '7';
    nums['T'] = nums['U'] = nums['V'] = '8';
    nums['W'] = nums['X'] = nums['Y'] = '9';

    string name;
    fin >> name;

    string candidate;
    bool matched = false;
    while(names >> candidate){
        if(candidate.size() != name.size()){
            continue;
        }
        bool match = true;
        for(int i = 0; i < name.size(); i++){
            if(nums[candidate[i]] != name[i]){
                match = false;
            }
        }
        if(match){
            matched = true;
            fout << candidate << endl;
        }
    }
    if(!matched){
        fout << "NONE" << endl;
    }

    names.close();
    fin.close();
    fout.close();
    return 0;
}