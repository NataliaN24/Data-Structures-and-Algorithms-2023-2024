#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, list<pair<int, int>>> graph;

    for (int i = 0; i < M; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x].push_back({ y, w });
        graph[y].push_back({ x, w });
    }

    int K;
    cin >> K;

    vector<int> path(K);
    for (int i = 0; i < K; ++i) {
        cin >> path[i];
    }

    int path_length = 0;
    bool is_valid = true;

    for (int i = 0; i < K - 1; ++i) {
        int u = path[i];
        int v = path[i + 1];
        bool edge_found = false;

        for (const auto& neighbor : graph[u]) {
            if (neighbor.first == v) {
                path_length += neighbor.second;
                edge_found = true;
                break;
            }
        }

        if (!edge_found) {
            is_valid = false;
            break;
        }
    }

    if (is_valid) {
        cout << path_length << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
