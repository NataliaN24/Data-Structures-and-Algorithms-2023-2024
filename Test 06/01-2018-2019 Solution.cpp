--the solution is from stoyan zlatev
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to,weight;
    bool operator>(const Edge&other)const{
        return weight>other.weight;
    }
};

unordered_map<int,vector<Edge>>town;
void shortestPath(const int&value,vector<int>&distances)
{
    distances[value]=0;
    priority_queue<Edge,vector<Edge>,greater<Edge>>pq;
    pq.push({value,0});
    while(!pq.empty()){
        int currentNode=pq.top().to;
        int currentDistance=pq.top().weight;
        pq.pop();
        if(currentDistance>distances[currentNode]){
            continue;
        }
        for(const auto&e:town[currentNode]){
            int nextNode=e.to;
            int nextDistance=e.weight;
            int totalDistance=nextDistance+currentDistance;
            
            if(totalDistance<distances[nextNode]){
                distances[nextNode]=totalDistance;
                pq.push({nextNode,totalDistance});
            }
            
        }
    }
}
int main() {
   int n,m,from,to,weight,start;
    cin>>n>>m;
    vector<int>distances(n+1,INT_MAX);
    for(int i=0;i<m;i++){
        cin>>from>>to>>weight;
        town[from].push_back({to,weight});
        town[to].push_back({from,weight});
    }
    cin>>start;
    shortestPath(start,distances);
    for(int i=1;i<=n;i++){
        if(i!=start){
            if(distances[i]!=INT_MAX){
                cout<<distances[i]<<" ";
            }
            else{
                cout<<-1<<" ";
            }
        }
    }
}
