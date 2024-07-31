#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;


int main() {
   int n,m;
    cin>>n>>m;
    unordered_map<string,long long>cities;
    for(int i=0;i<n;i++){
        string name;
        long long  cost;
        cin>>name>>cost;
        cities[name]=cost;
    }
    long long  sum=0;
    for(int i=0;i<m;i++){
        string  city;
        cin>>city;
        sum+=cities[city];
        
    }
    cout<<sum<<endl;
}
