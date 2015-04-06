/*
ID: gespo891
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("ride.in");
    ofstream fout ("ride.out");
    string group, comet;
    int groupnum = 1, cometnum = 1;
    fin >> comet >> group;
    for(auto c: comet){
      cometnum *= (c - 'A' + 1);
    }
    for(auto c: group){
      groupnum *= (c - 'A' + 1);
    }
    if(cometnum % 47 == groupnum % 47){
      fout << "GO" << endl;
    } else {
      fout << "STAY" << endl;
    }
    fin.close();
    fout.close();
    return 0;
}