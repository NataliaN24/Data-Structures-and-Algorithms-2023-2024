#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
------------------------------------------------------FIRST SOLUTION------------------------------------------------------------------------------------------------
int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, unordered_map<int, int>> graph;
    
    for (int i = 0; i < M; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        graph[x][y] = w;
        graph[y][x] = w;  
    }
    
    int K;
    cin >> K;
    
    vector<int> path(K);
    for (int i = 0; i < K; ++i) {
        cin >> path[i];
    }
    
   
    int totalLength = 0;
    bool isValidPath = true;
    
    for (int i = 0; i < K - 1; ++i) {
        int u = path[i];
        int v = path[i + 1];
        if (graph[u].find(v) == graph[u].end()) {
            isValidPath = false;
            break;
        }
        totalLength += graph[u][v];
    }
    
    if (isValidPath) {
        cout << totalLength << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}

------------------------------------------------------SECOND SOLUTION------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList; 
    vector<vector<int>> weights; 

    Graph(int V) : vertices(V), adjList(V), weights(V, vector<int>(V, -1)) {}

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
        weights[u][v] = w;
        weights[v][u] = w;
    }

    int findPathLength(const vector<int>& sequence) {
        int length = 0;

        for (int i = 0; i < sequence.size() - 1; ++i) {
            int u = sequence[i];
            int v = sequence[i + 1];

            int edgeWeight = getEdgeWeight(u, v);
            if (edgeWeight == -1) {
            
                return -1;
            }

            length += edgeWeight;
        }

        return length;
    }

private:
    int getEdgeWeight(int u, int v) {
        return weights[u][v];
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    for (int i = 0; i < M; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        graph.addEdge(x, y, w);
    }

    int K;
    cin >> K;

    vector<int> sequence(K);
    for (int i = 0; i < K; ++i) {
        cin >> sequence[i];
    }

    int pathLength = graph.findPathLength(sequence);

    cout << pathLength << endl;

    return 0;
}
