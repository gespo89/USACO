/*
ID: gespo891
PROG: hamming
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N, B, D;

int hamming_distance(int a, int b){
    int diff = a^b, count = 0;
    while(diff){
        diff &= diff - 1;
        count++;
    }
    return count;
}

int main() {
    ifstream fin ("hamming.in");
    ofstream fout ("hamming.out");
    fin >> N >> B >> D;
    vector<int> out;
    int current = 0;
    while(out.size() < N){
        bool use = true;
        for(int i : out)
            if(hamming_distance(current, i) < D)
                use = false;
        if(use)
            out.push_back(current);
        ++current;
    }

    bool first = true;
    for(int i = 0; i < out.size(); i++){
        if(first){
            first = false;
        } else if (i % 10 == 0){
            fout << endl;
        } else {
            fout << " ";
        }
        fout << out[i];
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}