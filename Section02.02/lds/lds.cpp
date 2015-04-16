/*
ID: gespo891
PROG: ldc
LANG: C++11
*/
#include <fstream>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;

int lds(vector<int> &vals){
    vector<int> best;
    for(auto it = vals.rbegin(); it != vals.rend(); it++){
        auto bit = best.rbegin();
        for(; bit != best.rend(); bit++){
            if(*it >= *bit)
                break;
            *bit = *it;
        }
        if(bit == best.rbegin())
            best.push_back(*it);
    }
    return best.size();
}

int main() {
    unsigned long seed = std::chrono::system_clock::now().time_since_epoch().count();

    vector<int> vals;
    for(int i = 0; i < 100000; i++){
        vals.push_back(i);
    }
    shuffle(vals.begin(), vals.end(), default_random_engine(seed));
    cout << lds(vals) << endl;
    return 0;
}