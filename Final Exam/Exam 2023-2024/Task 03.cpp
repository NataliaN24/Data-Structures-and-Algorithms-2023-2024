#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool hasCycle(int node, int parent, unordered_map<int, vector<int>>& graph, unordered_set<int>& visited) {
    visited.insert(node);
    
    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            if (hasCycle(neighbor, node, graph, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
           
            return true;
        }
    }
    
    return false;
}

int countComponentsWithCycles(int n, unordered_map<int, vector<int>>& graph) {
    unordered_set<int> visited;
    int count = 0;
    
    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end()) {
            
            if (hasCycle(i, -1, graph, visited)) {
                ++count;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        unordered_map<int, vector<int>> graph;
        
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        cout << countComponentsWithCycles(n, graph) << '\n';
    }
    
    return 0;
}
