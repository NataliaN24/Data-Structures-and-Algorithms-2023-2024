#include <iostream>
#include <vector>

using namespace std;

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
    int N, M;
    cin >> N >> M;

    UnionFind uf(N + 1); 

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        uf.unionSets(u, v);
    }

    int K;
    cin >> K;

    vector<int> results;

    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        if (uf.find(x) == uf.find(y)) {
            results.push_back(1);
        } else {
            results.push_back(0);
        }
    }

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
