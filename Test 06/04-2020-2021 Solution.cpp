--from stoyan solution
#include <bits/stdc++.h>

using namespace std;

unordered_map<int,vector<int>>graph;
unordered_map<int,bool>visited;
bool hasCycle=false;


void dfs(int value,set<int>&values){
    visited[value]=true;
    values.insert(value);
    
    for(const auto&e:graph[value]){
        if(values.find(e)!=values.end()){
            hasCycle=true;
            return;
        }
        if(!visited[e]){
            dfs(e,values);
        }
    }
    values.erase(value);
}
int main(){
    int q,n,e,start,end,w;
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>n>>e;
        hasCycle=false;
        for(int j=0;j<n;j++){
            graph[j];
        }
        for(int j=0;j<e;j++){
            cin>>start>>end>>w;
            graph[start].push_back(end);
        }
        set<int>values;
        for(const auto&el:graph){
            if(!visited[el.first]){
                dfs(el.first,values);
                if(hasCycle){
                    break;
                }
            }
        }
        cout<<hasCycle;
        graph.clear();
        visited.clear();
    }
    
}
