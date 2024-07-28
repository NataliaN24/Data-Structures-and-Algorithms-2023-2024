#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>

using namespace std;


int main() {
    int n;
    cin >> n;
    unordered_map<int, int>count;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        count[id]++;
    }
    int user=0;
    int product=0;
   for(const auto&pair:count){
       int id=pair.first;
       int productCount=pair.second;
       if(productCount%10!=0){
           user++;
           product+=productCount%10;
       }
   }
    cout << user<<" " << product << endl;

}
