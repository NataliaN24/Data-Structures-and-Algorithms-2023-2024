#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


struct Edge {
    int to;
    int weight;
};


struct Node {
    int index;
    int distance;
};

struct dist {
    bool operator()(const Node& a, const Node& b) const {
        return a.distance > b.distance;
    }
};


int findShortPath(int start, int end, vector<vector<Edge>>& graph) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    priority_queue<Node, vector<Node>, dist> pq;
    pq.push({ start, 0 });

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.index == end) {
            return distance[end];
        }

        for (const Edge& edge : graph[current.index]) {
            int newDistance = distance[current.index] + edge.weight;
            if (newDistance < distance[edge.to]) {
                distance[edge.to] = newDistance;
                pq.push({ edge.to, newDistance });
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> graph(n + 1); 

    for (int i = 0; i < m; ++i) {
        int u, v, len;
        cin >> u >> v >> len;
        graph[u].push_back({ v, len });
        graph[v].push_back({ u, len }); 
    }

    int startIndex, endIndex;
    cin >> startIndex >> endIndex;

    int shortestPath = findShortPath(startIndex, endIndex, graph);
    cout << shortestPath << endl;

    return 0;
}
