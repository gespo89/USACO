/*
ID: gespo891
PROG: cowtour
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <float.h>
#include <set>

using namespace std;

int N;
vector<pair<int,int>> locs;
vector<vector<double>> dist;
vector<string> edges;
vector<double> maxd;
set<int> g1, g2;
vector<vector<int>> components;
vector<double> maxc;
set<int> visited;

void fill(int v, int i){
    if(!visited.insert(v).second) return;
    components[i].push_back(v);
    for(int j = 0; j < N; j++)
        if(dist[v][j] != DBL_MAX)
            fill(j, i);
}

double calcdist(int a, int b){
    auto pa = locs[a];
    auto pb = locs[b];
    return(sqrt(pow(pa.first - pb.first, 2) + pow(pa.second - pb.second, 2)));
}

int main() {
    ifstream fin ("cowtour.in");
    auto outfile = fopen("cowtour.out", "w");
    fin >> N;
    for(int i = 0; i < N; i++){
        pair<int, int> coords;
        fin >> coords.first >> coords.second;
        locs.push_back(coords);
        dist.push_back(vector<double>(N, DBL_MAX));
    }
    string line;
    getline(fin, line);
    while(getline(fin, line)){
        edges.push_back(line);
    }

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(edges[i][j] == '1' || i == j)
                dist[i][j] = dist[j][i] = calcdist(i, j);

    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    maxd = vector<double>(N, 0);
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(dist[i][j] != DBL_MAX)
                maxd[i] = max(maxd[i], dist[i][j]);

    int group = 0;
    for(int v = 0; v < N; v++){
        if(visited.find(v) == visited.end()) {
            components.push_back(vector<int>());
            fill(v, group++);
        }
    }

    for(int i = 0; i < components.size(); i++){
        double worst = 0;
        for(auto v: components[i])
            worst = max(worst, maxd[v]);
        maxc.push_back(worst);
    }


    double out = DBL_MAX;

    for(int i = 0; i < components.size(); i++)
        for(int j = i + 1; j < components.size(); j++)
            {
                if(i == j) continue;
                auto c1 = components[i], c2 = components[j];
                for(int p1: c1)
                    for(int p2: c2){
                        double val = min(out, maxd[p1] + maxd[p2] + calcdist(p1, p2));
                        val = max(val, max(maxc[i], maxc[j]));
                        out = min(out, val);
                    }
            }

    fprintf(outfile, "%.6f\n", out);

    fin.close();
    fclose(outfile);
    return 0;
}