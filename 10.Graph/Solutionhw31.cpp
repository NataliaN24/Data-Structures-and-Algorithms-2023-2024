#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

int shortestDist(vector<vector<int>>& graph, vector<int>& groups, int friendGroup) {
    int minDistance = INT_MAX;
    int n = graph.size();

    for (int i = 0; i < n; ++i) {
        if (groups[i] == friendGroup) {
            vector<int> distance(n, -1);
            queue<int> q;
            q.push(i);
            distance[i] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    if (distance[neighbor] == -1) {
                        distance[neighbor] = distance[curr] + 1;
                        q.push(neighbor);
                    }
                }
            }

            for (int j = 0; j < n; ++j) {
                if (groups[j] == friendGroup && distance[j] != -1 && distance[j] < minDistance && i != j) {
                    minDistance = distance[j];
                }
            }
        }
    }

    return minDistance == INT_MAX ? -1 : minDistance;
}

int main() {
    int H, M;
    cin >> H >> M;

    vector<vector<int>> graph(H);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u - 1, v - 1);
    }

    vector<int> groups(H);
    for (int i = 0; i < H; ++i) {
        cin >> groups[i];
    }

    int group;
    cin >> group;

    int result = shortestDist(graph, groups, group);
    cout << result << endl;

    return 0;
}
