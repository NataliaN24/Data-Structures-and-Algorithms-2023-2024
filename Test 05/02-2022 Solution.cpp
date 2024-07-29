#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>graph;
vector<int>subtreeSize;
vector<bool>visited;

void dfs(int node,int parent){
    subtreeSize[node]=1;
    visited[node]=true;
    
    for(int n:graph[node]){
        if(!visited[n]){
            dfs(n,node);
            subtreeSize[node]+=subtreeSize[n];
        }
    }
    
}
int main(){
    int v,e;
    cin>>v>>e;
     graph.resize(v + 1);     
    subtreeSize.resize(v + 1, 0);
    visited.resize(v+ 1, false);
    
    
    vector<pair<int,int>>edges(e);
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges[i]={u,v};
        graph[u].push_back(v);
        graph[v].push_back(u);
        
    }
    dfs(1,-1);
    int removableEdges=0;
    
    for(const auto&edge:edges){
        int u=edge.first;
        int v=edge.second;
        
        if(subtreeSize[u]<subtreeSize[v]){
            swap(u,v);
        }
        if(subtreeSize[v]%2==0){
            removableEdges++;
        }
    }
    cout<<removableEdges<<endl;
}
