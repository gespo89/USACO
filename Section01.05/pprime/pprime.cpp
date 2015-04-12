/*
ID: gespo891
PROG: pprime
LANG: C++11
*/
#include <fstream>
#include <algorithm>

using namespace std;

vector<long> palindromes;

void add_palindromes(int n){
    for(int i = 1; i <= n; i++){
        int middle = (i - 1) / 2;
        for(long j = pow(10, middle); j < pow(10, middle+1); j++){
            long k, num;
            k = num = j;
            if(i % 2)
                num /= 10;
            while(k > 0){
                num *= 10;
                num += (k % 10);
                k /= 10;
            }
            palindromes.push_back(num);
        }
    }
}

bool is_prime(long n){
    for(long i = 2; i <= sqrt(n); i++)
        if(n % i == 0){
            return false;
        }
    return true;
}

int main() {
    ifstream fin ("pprime.in");
    ofstream fout ("pprime.out");

    int L, R;
    fin >> L >> R;
    add_palindromes((int) log10(R) + 1);
    for(int i: palindromes){
        if(i >= L && i <= R && is_prime(i))
            fout << i << endl;
    }


    fin.close();
    fout.close();
    return 0;
}