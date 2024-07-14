#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    vector<pair<int,int>>indexedArr(n);
    
    for(int i=0;i<n;i++){
        indexedArr[i]={arr[i],i};
    }
    sort(indexedArr.begin(),indexedArr.end());
    
    vector<int>result(n);
    
    for(int i=0;i<n;i++){
        result[indexedArr[i].second]=i;
    }
    
    for(int i=0;i<n;i++){
        cout<<result[i]<<" ";
    }
    
}
