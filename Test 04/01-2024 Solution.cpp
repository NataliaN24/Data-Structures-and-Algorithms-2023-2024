#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


int main() {
   int n,s;
    cin>>n>>s;
    priority_queue<int,vector<int>,greater<int>>nums;
    for(int i=0;i<n;++i){
        int value;
        cin>>value;
        nums.push(value);
    }
    int count=0;
    
    while(nums.size()>1){
        int s1=nums.top();
        nums.pop();
        
        if(s1>=s){
            cout<<count;
            return 0;
        }
        int s2=nums.top();
        nums.pop();
        
        int s3=s1+2*s2;
        nums.push(s3);
        count++;
    }
    if(nums.top()>=s && !nums.empty()){
        cout<<count;
    }
    else{
        cout<<-1;
    }
}
