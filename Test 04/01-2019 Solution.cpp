#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;


int main() {
   int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>result;
    
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num==-1){
            if(!pq.empty()){
                result.push_back(pq.top());
                    pq.pop();
            }
        }
        else{
            pq.push(num);
        }
        
    }
    for(int i:result){
        cout<<i<<" ";
    }
    
}
