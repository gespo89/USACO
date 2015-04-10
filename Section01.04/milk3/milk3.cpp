/*
ID: gespo891
PROG: milk3
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

void process(vector<int>);

set<vector<int>> processed;
set<int> out;

int capacities[3];


int main() {
    ifstream fin ("milk3.in");
    ofstream fout ("milk3.out");

    fin >> capacities[0] >> capacities[1] >> capacities[2];

    process(vector<int>{0, 0, capacities[2]});

    bool first = true;
    for(auto i: out){
        if(first){
            first = false;
        } else {
            fout << " ";
        }
        fout << i;
    }
    fout << endl;
    fin.close();
    fout.close();
    return 0;
}

void process(vector<int> buckets){
    if(processed.find(buckets) == processed.end()){
        processed.insert(buckets);
        if(buckets[0] == 0){
            out.insert(buckets[2]);
        }
        for(int i = 0; i < 3; i++){
            for(int j = i + 1; j < i + 3; j++){
                int k = j % 3;
                int pour = min(buckets[i], capacities[k] - buckets[k]);
                buckets[i] -= pour;
                buckets[k] += pour;
                process(buckets);
                buckets[i] += pour;
                buckets[k] -= pour;
            }
        }
    }
}