#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

const int INF = 1e9;

struct Node {
    int destination;
    int weight;

    bool operator>(const Node &other) const {
        return this->weight > other.weight;
    }
};

void dijkstra(int start, const unordered_map<int, vector<Node>> &adj, vector<int> &dist) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.weight > dist[current.destination]) {
            continue;
        }

        if (adj.find(current.destination) != adj.end()) {
            for (const auto &edge : adj.at(current.destination)) {
                if (dist[current.destination] + edge.weight < dist[edge.destination]) {
                    dist[edge.destination] = dist[current.destination] + edge.weight;
                    pq.push({edge.destination, dist[edge.destination]});
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<Node>> adj;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int s;
    cin >> s;
    s--; 

    vector<int> dist(n, INF);

    dijkstra(s, adj, dist);

    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (dist[i] == INF) {
                cout << -1 << " ";
            } else {
                cout << dist[i] << " ";
            }
        }
    }
    cout << endl;

    return 0;
}
