#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;

    UnionFind uf(N + 1); // +1 to accommodate 1-based indexing

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }

    int K;
    cin >> K;

    for (int i = 0; i < K; ++i) {
        int u, v;
        cin >> u >> v;
        if (uf.find(u) == uf.find(v)) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }

    return 0;
}
