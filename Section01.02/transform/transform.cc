/*
ID: gespo891
PROG: transform
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<char>> rotate(vector<vector<char>>);
vector<vector<char>> flip(vector<vector<char>>);
int get_transform(vector<vector<char>>, vector<vector<char>>);
bool equal(vector<vector<char>>, vector<vector<char>>);

int main() {
    ifstream fin ("transform.in");
    ofstream fout ("transform.out");
    int size;
    fin >> size;
    vector<vector<char>> original, target;
    for(int i = 0; i < size; i++){
        string line;
        fin >> line;
        original.push_back(vector<char>(line.begin(), line.end()));
    }
    for(int i = 0; i < size; i++){
        string line;
        fin >> line;
        target.push_back(vector<char>(line.begin(), line.end()));
    }

    fout << get_transform(original, target) << endl;

    fin.close();
    fout.close();
    return 0;
}

int get_transform(vector<vector<char>> original, vector<vector<char>> target){
    vector<vector<char>> current = original;
    for(int i = 1; i <= 3; i++){
        current = rotate(current);
        if(current == target){
            return i;
        }
    }
    current = rotate(current);
    current = flip(current);
    if(current == target){
        return 4;
    }
     for(int i = 1; i <= 3; i++){
        current = rotate(current);
        if(current == target){
            return 5;
        }
    }
    if(original == target){
        return 6;
    }
    return 7;
}

bool equal(vector<vector<char>> original, vector<vector<char>> target){
    int size = original.size();
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(original[i][j] != target[i][j]){
                return false;
            }
        }
    }
    return true;
}

vector<vector<char>> rotate(vector<vector<char>> original){
    int size = original.size();
    vector<vector<char>> rotated(size);
    for(int i = 0; i < size; i++){
        rotated[i] = vector<char>(size);
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            rotated[i][j] = original[size - j - 1][i];
        }
    }
    return rotated;
}

vector<vector<char>> flip(vector<vector<char>> original){
    int size = original.size();
    vector<vector<char>> flipped(size);
    for(int i = 0; i < size; i++){
        flipped[i] = vector<char>(size);
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            flipped[i][j] = original[i][size - j - 1];
        }
    }
    return flipped;
}