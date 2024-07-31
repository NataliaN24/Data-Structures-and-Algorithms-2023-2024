#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
const int MOD = 1000000007;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    int source = 1, destination = N;
    
    vector<long long> dist(N + 1, INF);
    vector<long long> ways(N + 1, 0);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    dist[source] = 0;
    ways[source] = 1;
    pq.emplace(0, source);

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        if (current_dist > dist[u]) continue;

        for (const auto &[v, weight] : graph[u]) {
            long long new_dist = current_dist + weight;

            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                ways[v] = ways[u];
                pq.emplace(new_dist, v);
            } else if (new_dist == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD;
            }
        }
    }

    if (dist[destination] == INF) {
        cout << "-1 0\n";
    } else {
        cout << dist[destination] << " " << ways[destination] << "\n";
    }

    return 0;
}
