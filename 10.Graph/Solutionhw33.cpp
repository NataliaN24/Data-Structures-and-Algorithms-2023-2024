#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;


struct Edge {
    long town, cost;
};

long calculate(long N, long M, long K, long L, const vector<vector<Edge>>& graph) {
    vector<long> costForDisco(N + 1, K);
    vector<bool> visited(N + 1, false);
    priority_queue<pair<long, long>> pq;

    for (long i = 1; i <= N; ++i) {
        pq.push({ -costForDisco[i], i });
    }

    while (!pq.empty()) {
        long cost = -pq.top().first;
        long currentTown = pq.top().second;
        pq.pop();

        if (visited[currentTown]) {
            continue;
        }

        visited[currentTown] = true;

        for (const Edge& neighbor : graph[currentTown]) {
            long adjTown = neighbor.town;
            long costsFroPath = neighbor.cost;

            if (!visited[adjTown] && costForDisco[adjTown] > costsFroPath) {
                costForDisco[adjTown] = costsFroPath;
                pq.push({ -costForDisco[adjTown], adjTown });
            }
        }
    }

    long total = 0;
    for (long i = 1; i <= N; ++i) {
        total += costForDisco[i];
    }

    return total;
}

int main() {
    long num;
    cin >> num;

    for (long t = 0; t < num; ++t) {
        long N, M, K, L;
        cin >> N >> M >> K >> L;

        vector<vector<Edge>> graph(N + 1);

        for (long m = 0; m < M; ++m) {
            long x, y;
            cin >> x >> y;
            graph[x].push_back({ y, L });
            graph[y].push_back({ x, L });
        }

        long res = calculate(N, M, K, L, graph);
        cout << res << endl;
    }

    return 0;
}
