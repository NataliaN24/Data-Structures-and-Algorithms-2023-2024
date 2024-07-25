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
    unordered_map<int, int >count;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            count[num]++;

        }
    int undeliveredUsers=0;
    int undeliveredProducts=0;
    
        for(const auto &pair:count){
            if(pair.second%10!=0){
                undeliveredUsers++;
                undeliveredProducts +=pair.second%10;
            }
        }
    cout<<undeliveredUsers<<" "<<undeliveredProducts;
}
