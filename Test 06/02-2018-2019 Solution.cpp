#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>adj;
vector<int>subtreeSize;
int removableEdges=0;

int dfs(int node,int parent){
    int size=1;
    for(int neighbor:adj[node]){
        if(neighbor!=parent){
            int subtree=dfs(neighbor,node);
            if(subtree%2==0){
                removableEdges++;
            }
            else{
                size+=subtree;
            }
        }
    }
    return size;
}

int main() {
   int v,e;
    cin>>v>>e;
    adj.resize(v+1);
    subtreeSize.resize(v+1,0);
    
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<removableEdges<<endl;
    
}
