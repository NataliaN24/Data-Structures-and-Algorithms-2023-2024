#include <bits/stdc++.h>
//just one edge case is wrong with this code
using namespace std;

unordered_map<int, vector<int>> graph;

bool hasCycleUtil(int node, unordered_map<int, bool>& visited, unordered_map<int, bool>& recStack) {
    if (!visited[node]) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : graph[node]) {
            if (!visited[neighbor] && hasCycleUtil(neighbor, visited, recStack)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[node] = false;
    return false;
}

bool detectCycle(int V) {
    unordered_map<int, bool> visited;
    unordered_map<int, bool> recStack;

    for (const auto& pair : graph) {
        if (!visited[pair.first]) {
            if (hasCycleUtil(pair.first, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int q, n, e, start, end, w;
    cin >> q;

    while (q--) {
        cin >> n >> e;
        graph.clear(); 

        for (int i = 0; i < e; ++i) {
            cin >> start >> end >> w;
            graph[start].push_back(end);
        }

        if (detectCycle(n)) {
            cout << "true ";
        } else {
            cout << "false ";
        }
    }
    cout << endl;

    return 0;
}
