#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


int main() {
  int n,s=0;
    cin>>n>>s;
    priority_queue<int,vector<int>,greater<int>>arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.push(num);
    }
    int count=0;
    while(arr.size()>1){
        int s1=arr.top();
        arr.pop();
        if(s1>=s){
            cout<<count;
            return 0;
        }
        int s2=arr.top();
        arr.pop();
        int s3=s1+2*s2;
        arr.push(s3);
        count++;
        
    }
    if(arr.top()>=s&&!arr.empty()){
        cout<<count<<endl;
        
    }
    else{
        cout<<-1;
    }
}
