/*
ID: gespo891
PROG: milk2
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin ("milk2.in");
    ofstream fout ("milk2.out");
    int times[1000000] = {};
    int count;
    fin >> count;
    for(int i = 0; i < count; i++){
        int start, stop;
        fin >> start >> stop;
        times[start]++;
        times[stop]--;
    }
    int max_idle, max_milk, cows, last;
    max_idle = max_milk = cows = last = 0;
    int interval = -1;
    for(int i = 0; i < 1000000; i++){
        cows += times[i];
        if(last == 0 && cows > 0){
            if(interval != -1){
                max_idle = max(max_idle, i - interval);
            }
            interval = i;
        }
        if(last > 0 && cows == 0){
            if(interval != -1){
                max_milk = max(max_milk, i - interval);
            }
            interval = i;
        }
        last = cows;
    }

    fout << max_milk << " " << max_idle << endl;
    fin.close();
    fout.close();
    return 0;
}