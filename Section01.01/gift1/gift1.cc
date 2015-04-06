/*
ID: gespo891
PROG: gift1
LANG: C++11
*/
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int np, total, count;
    vector<string> names;
    string name;
    unordered_map<string, int> totals;
    fin >> np;
    for(int i = 0; i < np; i++){
      fin >> name;
      names.push_back(name);
      totals[name] = 0;
    }
    while(fin >> name){
      fin >> total >> count;
      if(count > 0){
        totals[name] = totals[name] - (total - (total % count));
        for(int i = 0; i < count; i++){
          fin >> name;
          totals[name] += total / count;
        }
      }
    }
    for(auto current: names){
      fout << current << " " << totals[current] << endl;
    }
    
    fin.close();
    fout.close();
    return 0;
}