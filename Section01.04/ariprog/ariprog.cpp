/*
ID: gespo891
PROG: ariprog
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int length, bound;
set<int> bisquares;
vector<pair<int, int>> results;

int main() {
    ifstream fin ("ariprog.in");
    ofstream fout ("ariprog.out");
    fin >> length >> bound;
    for(int i = 0; i <= bound; i++){
        for(int j = i; j <= bound; j++){
            bisquares.insert(pow(i, 2) + pow(j, 2));
        }
    }

    for(int i = 0; i < pow(bound, 2); i++){
        int start = 0, length = 1;
        for(int j = 0; j < 2 * pow(bound, 2); j++){

        }
    }



    fin.close();
    fout.close();
    return 0;
}