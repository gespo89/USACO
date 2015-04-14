/*
ID: gespo891
PROG: castle
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>

using namespace std;

const int WEST = 1;
const int NORTH = 2;
const int EAST = 4;
const int SOUTH = 8;

int M, N;
vector<vector<int>> layout;
vector<vector<int>> rooms;
map<int, map<int, pair<pair<int, int>, char>>> adjacent;
vector<int> sizes;

void fill(int y, int x, int val){
    if(rooms[y][x] != -1){
        return;
    }
    rooms[y][x] = val;
    sizes[val]++;
    if(!(layout[y][x] & NORTH))
        fill(y - 1, x, val);
    if(!(layout[y][x] & SOUTH))
        fill(y + 1, x, val);
    if(!(layout[y][x] & EAST))
        fill(y, x + 1, val);
    if(!(layout[y][x] & WEST))
        fill(y, x - 1, val);
}

int main(){
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");
    fin >> M >> N;
    for(int i = 0; i < N; i++){
        vector<int> row;
        for(int j = 0; j < M; j++){
            int val;
            fin >> val;
            row.push_back(val);
        }
        layout.push_back(row);
        rooms.push_back(vector<int>(M, -1));
    }

    int room = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(rooms[i][j] == -1) {
                sizes.push_back(0);
                fill(i, j, room++);
            }
        }
    }

    for(int i = M - 1; i >= 0; i--){
        for(int j = 0; j < N; j++) {
            int a = rooms[j][i], b;
            if (i + 1 < M){
                b = rooms[j][i + 1];
                if (a != b) {
                    adjacent[a][b] = pair<pair<int, int>, char>{pair<int, int>{j + 1, i + 1}, 'E'};
                    adjacent[b][a] = pair<pair<int, int>, char>{pair<int, int>{j + 1, i + 1}, 'E'};
                }
            }
            if(j > 0){
                b = rooms[j - 1][i];
                if(a != b){
                    adjacent[a][b] = pair<pair<int, int>, char>{pair<int, int>{j + 1, i + 1}, 'N'};
                    adjacent[b][a] = pair<pair<int, int>, char>{pair<int, int>{j + 1, i + 1}, 'N'};
                }
            }
        }
    }

    int max_wall_size = 0;
    pair<pair<int, int>, char> max_wall_pair;

    for(auto i: adjacent){
        for(auto j: i.second){
            if(sizes[i.first] + sizes[j.first] > max_wall_size){
                max_wall_size = sizes[i.first] + sizes[j.first];
                max_wall_pair = j.second;

            } else if(sizes[i.first] + sizes[j.first] == max_wall_size){
                pair<pair<int, int>, char> &candidate = j.second;
                bool better = false;
                if (candidate.first.second < max_wall_pair.first.second){
                    better = true;
                } else if(candidate.first.second == max_wall_pair.first.second &&
                          candidate.first.first > max_wall_pair.first.first){
                    better = true;
                } else if(candidate.first.second == max_wall_pair.first.second &&
                          candidate.first.first == max_wall_pair.first.first &&
                          candidate.second == 'N'){
                    better = true;
                }
                if(better){
                    max_wall_size = sizes[i.first] + sizes[j.first];
                    max_wall_pair = j.second;
                }
            }
            auto coords = j.second.first;
            auto dir = j.second.second;
        }
    }

    int max_room = 0;
    for(int i: sizes){
        max_room = max(max_room, i);
    }

    fout << sizes.size() << endl;
    fout << max_room << endl;
    fout << max_wall_size << endl;
    fout << max_wall_pair.first.first << " " << max_wall_pair.first.second << " " << max_wall_pair.second << endl;

    fin.close();
    fout.close();
    return 0;
}