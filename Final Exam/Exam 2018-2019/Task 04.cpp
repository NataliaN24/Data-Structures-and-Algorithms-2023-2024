#include <iostream>
#include <vector>
using namespace std;

bool isCyclicUtil(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor] && isCyclicUtil(neighbor, adj, visited, recStack)) {
                return true;
            }
            else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (isCyclicUtil(i, adj, visited, recStack)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> results;

    for (int i = 0; i < n; i++) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        for (int j = 0; j < E; j++) {
            int xi, yi, wi;
            cin >> xi >> yi >> wi;
            adj[xi - 1].push_back(yi - 1); 
        }

        if (isCyclic(V, adj)) {
            results.push_back("true");
        } else {
            results.push_back("false");
        }
    }

    for (const string& result : results) {
        cout << result << " ";
    }

    return 0;
}
