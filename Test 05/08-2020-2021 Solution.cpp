#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>

using namespace std;

void dfs(int node, int K, int currentLength, int currentDepth, const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, map<int, int>& pathLengths) {
    if (currentDepth == K) {
        pathLengths[currentLength]++;
        return;
    }

    visited[node] = true;

    for (const auto& edge : adj[node]) {
        int neighbor = edge.first;
        int weight = edge.second;

        if (!visited[neighbor]) {
            dfs(neighbor, K, currentLength + weight, currentDepth + 1, adj, visited, pathLengths);
        }
    }

    visited[node] = false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < E; ++i) {
        int vi1, vi2, wi;
        cin >> vi1 >> vi2 >> wi;
        adj[vi1 - 1].emplace_back(vi2 - 1, wi);
    }

    int K;
    cin >> K;

    map<int, int> pathLengths;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        dfs(i, K, 0, 0, adj, visited, pathLengths);
    }

    if (pathLengths.empty()) {
        cout << -1 << endl;
    } else {
        int mostCommonLength = -1;
        int maxFrequency = 0;

        for (const auto& [length, frequency] : pathLengths) {
            if (frequency > maxFrequency || (frequency == maxFrequency && length > mostCommonLength)) {
                mostCommonLength = length;
                maxFrequency = frequency;
            }
        }

        cout << mostCommonLength << endl;
    }

    return 0;
}
