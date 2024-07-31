#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;


int main() {
   int k;
    cin>>k;
    unordered_map<int,vector<int>>graph;
    for(int i=0;i<k;i++){
        int x;
        int y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        
    }
    unordered_map<int,int>distances;
    queue<int>q;
    q.push(0);
    distances[0]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(int neighbor:graph[node])
        {
            if(distances.find(neighbor)==distances.end())
            {
                distances[neighbor]=distances[node]+1;
                q.push(neighbor);
            }
        }
    }
    int sum=0;
    for(const auto&pair:distances){
        sum+=pair.second;
    }
    cout<<sum;
}
