/*
ID: gespo891
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int length;
    string beads;

    fin >> length >> beads;
    beads += beads;
    vector<vector<int>> left(2);
    vector<vector<int>> right(2);
    left[0] = vector<int>(beads.size());
    left[1] = vector<int>(beads.size());
    right[0] = vector<int>(beads.size());
    right[1] = vector<int>(beads.size());
    int red = 0;
    int blue = 0;
    for(int i = 0; i < beads.size(); i++){
        char c = beads[i];
        if(c == 'w'){
            red++;
            blue++;
        } else if (c == 'r'){
            red++;
            blue = 0;
        } else {
            blue++;
            red = 0;
        }
        left[0][i] = red;
        left[1][i] = blue;
    }
    red = blue = 0;
    for(int i = beads.size() - 1; i >= 0 ; i--){
        right[0][i] = red;
        right[1][i] = blue;
        char c = beads[i];
        if(c == 'w'){
            red++;
            blue++;
        } else if (c == 'r'){
            red++;
            blue = 0;
        } else {
            blue++;
            red = 0;
        }
    }
    int maxlength = 0;
    for(int i = 0; i < beads.size(); i++){
       int leftmax = max(left[0][i], left[1][i]);
       int rightmax = max(right[0][i], right[1][i]);
       maxlength = max(maxlength, leftmax + rightmax);
    }
    maxlength = min(maxlength, length);

    fout << maxlength << endl;
    fin.close();
    fout.close();
    return 0;
}