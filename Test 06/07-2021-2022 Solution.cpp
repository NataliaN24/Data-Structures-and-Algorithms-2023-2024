#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
------------------------------------------------------FIRST SOLUTION------------------------------------------------------------------------------------------------
class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                ++rank[rootX];
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

int main() {
    int T;
    cin >> T;
    vector<int> results;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        UnionFind uf(X);

        for (int i = 0; i < Y; ++i) {
            int x, y;
            cin >> x >> y;
            uf.unionSets(x, y);
        }

        unordered_set<int> uniqueComponents;
        for (int i = 0; i < X; ++i) {
            uniqueComponents.insert(uf.find(i));
        }

        results.push_back(uniqueComponents.size());
    }

    for (size_t i = 0; i < results.size(); ++i) {
        cout << results[i] << " ";
    }
    cout << endl;

    return 0;
}
------------------------------------------------------SECOND SOLUTION------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    Graph(int V) : vertices(V), adjList(V) {}

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int countDistricts() {
        vector<bool> visited(vertices, false);
        int districts = 0;

        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited);
                districts++;
            }
        }

        return districts;
    }

private:
    void dfs(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int neighbor : adjList[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;

        Graph graph(X);

        for (int i = 0; i < Y; ++i) {
            int x, y;
            cin >> x >> y;
            graph.addEdge(x, y);
        }

        int districts = graph.countDistricts();
        cout << districts << " ";
    }

    return 0;
}

