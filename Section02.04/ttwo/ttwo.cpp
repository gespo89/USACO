/*
ID: gespo891
PROG: ttwo
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int const UP = 0;
int const RIGHT = 1;
int const DOWN = 2;
int const LEFT = 3;

int const W = 10, H = 10;
vector<string> board;

struct mover{
    int x, y, dir;
};

void simulate(mover & m){
    int x = m.x, y = m.y, dir = m.dir;
    if(dir == UP)
        y--;
    else if(dir == RIGHT)
        x++;
    else if (dir == DOWN)
        y++;
    else
        x--;

    if(x >= 0 && x < W && y >= 0 && y < H && board[y][x] != '*'){
        m.x = x;
        m.y = y;
    } else {
        m.dir = (m.dir + 1) % 4;
    }
}



int main() {
    ifstream fin ("ttwo.in");
    ofstream fout ("ttwo.out");

    string line;
    while(fin >> line)
        board.push_back(line);

    mover f, c;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(board[i][j] == 'F')
                f = mover{j,i,UP};
            if(board[i][j] == 'C')
                c = mover{j,i,UP};
        }
    }

    int meet = 0;
    for(int i = 1; i <= 160000 && meet == 0; i++){
        simulate(f);
        simulate(c);
        if(f.x == c.x && f.y == c.y)
            meet = i;
    }
    fout << meet << endl;

    fin.close();
    fout.close();
    return 0;
}