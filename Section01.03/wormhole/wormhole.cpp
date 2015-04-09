/*
ID: gespo891
PROG: wormhole
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

struct point{
    int x;
    int y;
};

int n, total = 0;
vector<int> pairs;
vector<int> next_portal;
vector<point> portals;

void count();
int first_empty();
bool has_loop();

int main() {
    ifstream fin ("wormhole.in");
    ofstream fout ("wormhole.out");

    fin >> n;
    pairs = vector<int> (n, -1);
    next_portal = vector<int> (n, -1);

    for(int i = 0; i < n; i++){
        point portal;
        fin >> portal.x >> portal.y;
        portals.push_back(portal);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(portals[i].y == portals[j].y and portals[j].x > portals[i].x){
                if(next_portal[i] == -1 || portals[next_portal[i]].x > portals[j].x){
                    next_portal[i] = j;
                }
            }
        }
    }

    count();
    fout << total << endl;
    fin.close();
    fout.close();
    return 0;
}

void count(){
    int i = first_empty();
    if(i == -1){
        if(has_loop()){
            total++;
        }
        return;
    }
    for(int j = i + 1; j < n; j++){
        if(pairs[j] == -1) {
            pairs[i] = j;
            pairs[j] = i;
            count();
            pairs[i] = pairs[j] = -1;
        }
    }
}

int first_empty(){
    for(int i = 0; i < n; i++){
        if(pairs[i] == -1){
            return i;
        }
    }
    return -1;
}

bool has_loop(){
    for(int i = 0; i < n; i++){
        int portal = i;
        for(int j = 0; j < n; j++){
            portal = next_portal[pairs[portal]];
            if(portal == -1){
                break;
            }
        }
        if(portal != -1){
            return true;
        }
    }
    return false;
}