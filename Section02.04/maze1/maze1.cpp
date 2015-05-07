/*
ID: gespo891
PROG: maze1
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>

using namespace std;

int W, H;
vector<string> maze;
vector<vector<int>> distances;

bool canmove(pair<int, int> const & a, pair<int, int> const & b){
    int xa = 1 + 2 * a.first, xb = 1 + 2 * b.first, x = (xa + xb)/2;
    int ya = 1 + 2*a.second, yb = 1 + 2 * b.second, y = (ya + yb)/2;
    if(b.first < 0 || b.first >= W || b.second < 0 || b.second >= H) return false;
    return (maze[y][x] == ' ');
}

int dist(int x, int y){
    queue<pair<pair<int,int>, int>> q;
    q.push(pair<pair<int,int>, int>{pair<int,int>{x, y}, 1});
    set<pair<int,int>> seen;
    while(!q.empty()){
        auto item = q.front();
        q.pop();
        if(!seen.insert(item.first).second) continue;
        int dist = item.second, x2 = item.first.first, y2 = item.first.second;
        distances[y2][x2] = min(distances[y2][x2], dist);
        pair<int,int> next = pair<int,int>{x2 + 1, y2};
        if(canmove(item.first, next))
            q.push(pair<pair<int,int>, int>{next, dist + 1});
        next = pair<int,int>{x2 - 1, y2};
        if(canmove(item.first, next))
            q.push(pair<pair<int,int>, int>{next, dist + 1});
        next = pair<int,int>{x2, y2 + 1};
        if(canmove(item.first, next))
            q.push(pair<pair<int,int>, int>{next, dist + 1});
        next = pair<int,int>{x2, y2 - 1};
        if(canmove(item.first, next))
            q.push(pair<pair<int,int>, int>{next, dist + 1});
    }
}

int main() {
    ifstream fin ("maze1.in");
    ofstream fout ("maze1.out");

    fin >> W >> H;
    string line;
    getline(fin, line);
    while(getline(fin, line)) {
        maze.push_back(line);
        distances.push_back(vector<int>(W, W*H + 1));
    }


    vector<pair<int,int>> outs;
    for(int i = 0; i < W; i++){
        if(maze[0][2*i + 1] == ' ')
            outs.push_back(pair<int, int>{i, 0});
        if(maze[2*H][2*i + 1] == ' ')
            outs.push_back(pair<int, int>{i, H - 1});
    }
    for(int i = 0; i < H; i++){
        if(maze[2*i + 1][0] == ' ')
            outs.push_back(pair<int, int>{0, i});
        if(maze[2*i + 1][2*W] == ' ')
            outs.push_back(pair<int, int>{W-1, i});
    }
    for(auto i: outs){
        dist(i.first, i.second);
    }
    int worst = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            worst = max(worst, distances[i][j]);
        }
    }
    fout << worst << endl;
    fin.close();
    fout.close();
    return 0;
}