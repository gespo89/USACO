/*
ID: gespo891
PROG: holstein
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

int V, G;
vector<int> requirements;
vector<vector<int>> feeds;

bool solve(vector<int> &vitamins, vector<int> &used, int index, int depth, int max_depth){
    if(index >= G || depth >= max_depth){
        return false;
    }
    used.push_back(index);
    for(int i = 0; i < V; i++){
        vitamins[i] += feeds[index][i];
    }
    bool done = true;
    for(int i = 0; i < V; i++){
        if(vitamins[i] < requirements[i]){
            done = false;
        }
    }
    if(done) {
        return true;
    } else {
        for (int i = index + 1; i < G; i++) {
            if(solve(vitamins, used, i, depth + 1, max_depth)){
                return true;
            }
        }
    }
    for(int i = 0; i < V; i++){
        vitamins[i] -= feeds[index][i];
    }
    used.pop_back();
    return false;
}

int main() {
    ifstream fin ("holstein.in");
    ofstream fout ("holstein.out");

    fin >> V;
    for(int i = 0; i < V; i++){
        int n;
        fin >> n;
        requirements.push_back(n);
    }

    fin >> G;

    for(int i = 0; i < G; i++){
        vector<int> feed;
        for(int j = 0; j < V; j++){
            int n;
            fin >> n;
            feed.push_back(n);
        }
        feeds.push_back(feed);
    }

    vector<int> solution;
    vector<int> counts(V, 0);
    int done = false;
    for(int i = 1; i <= G && !done; i++){
        for(int j = 0; j < G && !done; j++){
            if(solve(counts, solution, j, 0, i))
                done = true;
        }
    }

    fout << solution.size();
    for(int i: solution){
        fout << " " << i + 1;
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}