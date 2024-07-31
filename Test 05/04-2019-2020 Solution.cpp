#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    unordered_map<int,vector<int>>adj;
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int startCity=N;
    unordered_map<int,int>distances;
    queue<int>q;
    distances[startCity]=0;
    q.push(startCity);
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int neighbor:adj[current]){
            if(distances.find(neighbor)==distances.end()){
                distances[neighbor]=distances[current]+1;
                q.push(neighbor);
                
            }
        }
    }
    vector<int>result;
    for(int city=1;city<=N;++city){
        if(distances[city]==K){
            result.push_back(city);
        }
    }
    if(result.empty()){
        cout<<-1<<endl;
    }
    else{
        sort(result.begin(),result.end());
        for(int city:result){
            cout<<city<<" ";
        }
        cout<<endl;
    }
}
