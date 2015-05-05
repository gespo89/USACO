/*
ID: gespo891
PROG: prefix
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

bool dp[200001] = {true};
vector<string> prims;
string sequence;

int main() {
    int count = 0;
    ifstream fin ("prefix.in");
    ofstream fout ("prefix.out");
    string s;
    fin >> s;
    while(s != ".") {
        prims.push_back(s);
        fin >> s;
    }
    while(fin >> s){
        sequence += s;
    }

    for(int i = 0; i <= sequence.length(); i++){
        if(!dp[i]) continue;
        for(auto p: prims){
            if(i + p.size() > sequence.length())
                continue;
            bool good = true;
            for(int j = 0; j < p.size(); j++){
                if(sequence[i + j] != p[j]){
                    good = false;
                    break;
                }
            }
            if(good){
                dp[i + p.size()] = true;
            }
        }
    }

    int max = 0;
    for(int i = 0; i < 200000; i++)
        if(dp[i])
            max = i;

    fout << max << endl;

    fin.close();
    fout.close();
    return 0;
}