/*
ID: gespo891
PROG: friday
LANG: C++11
*/
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int leap_months[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

bool is_leap_year(int);


int main() {
    ifstream fin ("friday.in");
    ofstream fout ("friday.out");
    int year = 1900, day = 2, n;
    int days[7] = {};
    fin >> n;
    day = (day + 12) % 7;
    for(int i = 0; i < n; i++){
      int *counts;
      if(is_leap_year(year)){
        counts = leap_months;
      } else {
        counts = months;
      }
      for(int j = 0; j < 12; j++){
        days[day]++;
        day = (day + counts[j]) % 7;
      }
      year++;
    }

    for(int i = 0; i < 6; i++){
      fout << days[i] << " ";
    }
    fout << days[6] << endl;
    
    fin.close();
    fout.close();
    return 0;
}

bool is_leap_year(int year){
  if(year % 400 == 0){
    return true;
  } else if (year % 4 == 0 and year % 100 != 0){
    return true;
  } else{
    return false;
  }
}