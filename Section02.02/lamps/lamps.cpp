/*
ID: gespo891
PROG: lamps
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

int N, C;
set<vector<bool>> out;
vector<pair<int, bool>> end_state;

vector<bool> switch1(vector<bool> lamps){
    for(int i = 0; i < lamps.size(); i++)
        lamps[i] = !lamps[i];
    return lamps;
}

vector<bool> switch2(vector<bool> lamps){
    for(int i = 0; i < lamps.size(); i++)
        if(i % 2 == 0)
            lamps[i] = !lamps[i];
    return lamps;
}

vector<bool> switch3(vector<bool> lamps){
    for(int i = 0; i < lamps.size(); i++)
        if(i % 2)
            lamps[i] = !lamps[i];
    return lamps;
}

vector<bool> switch4(vector<bool> lamps){
    for(int i = 0; i < lamps.size(); i++)
        if(i % 3 == 0)
            lamps[i] = !lamps[i];
    return lamps;
}

bool possible(vector<bool> const & lamps){
    for(auto check: end_state) {
        if (lamps[check.first] != check.second)
            return false;
    }
    return true;
}

void solve(vector<bool> lamps, int flips){
    if(possible(lamps)){
        out.insert(lamps);
    }
    if(flips == C)
        return;
    solve(switch1(lamps), flips + 1);
    solve(switch2(lamps), flips + 1);
    solve(switch3(lamps), flips + 1);
    solve(switch4(lamps), flips + 1);
}

int main() {
    ifstream fin ("lamps.in");
    ofstream fout ("lamps.out");

    fin >> N >> C;
    C = min(4, C);
    int val;
    fin >> val;
    while(val != -1){
        end_state.push_back(make_pair(val - 1, true));
        fin >> val;
    }
    fin >> val;
    while(val != -1){
        end_state.push_back(make_pair(val - 1, false));
        fin >> val;
    }
    solve(vector<bool>(N, true), 0);
    for(vector<bool> v: out) {
        for(bool b: v)
            fout << b;
        fout << endl;
    }
    if(out.size() == 0)
        fout << "IMPOSSIBLE" << endl;


    fin.close();
    fout.close();
    return 0;
}