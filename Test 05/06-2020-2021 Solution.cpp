#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void bfs(int start, const unordered_map<int, vector<int>>& adj, vector<bool>& visited, int& component) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    component = 0;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        component++;
        for (int neighbor : adj.at(current)) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;  
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++) {
        int ci, cj;
        cin >> ci >> cj;
        adj[ci].push_back(cj);
        adj[cj].push_back(ci);
    }
    vector<bool> visited(m, false);
    int components = 0;
    for (int i = 0; i < m; i++) {
        if (!visited[i] && adj.find(i) != adj.end()) {
            int size = 0;
            bfs(i, adj, visited, size);
            if (size >= 2) {  
                components++;
            }
        }
    }
    cout << components << endl; 
    return 0;
}
