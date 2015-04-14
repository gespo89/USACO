/*
ID: gespo891
PROG: frac1
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

struct frac{
    int d;
    int n;
    double val;
};

int gcd(int m, int n){
    if(n == 0)
        return m;
    else
        return gcd(n, m%n);
}

int main() {
    ifstream fin ("frac1.in");
    ofstream fout ("frac1.out");
    int N;
    fin >> N;
    vector<frac> fracs;
    for(int d = 1; d <= N; d++)
        for(int n = 0; n <= d; n++)
            if(gcd(d, n) == 1)
                fracs.push_back(frac{d, n, (double)n/d});
    sort(fracs.begin(), fracs.end(), [](frac const &a, frac const &b) -> bool{
        return a.val < b.val;
    });

    for(frac f: fracs){
        fout << f.n << "/" << f.d << endl;
    }

    fin.close();
    fout.close();
    return 0;
}