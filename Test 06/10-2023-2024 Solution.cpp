#include <bits/stdc++.h>
using namespace std;

struct Edge {
    size_t v;
    size_t u;
};

vector<Edge> edges;
vector<size_t> parent, depth;

size_t findParent(size_t v) {
    if (v != parent[v]) {
        parent[v] = findParent(parent[v]); 
    }
    return parent[v];
}

void unionV(size_t v, size_t u) {
    size_t rootV = findParent(v);
    size_t rootU = findParent(u);

    if (rootV != rootU) {
        if (depth[rootV] < depth[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            if (depth[rootV] == depth[rootU]) {
                depth[rootV]++;
            }
        }
    }
}

int main() {
    size_t N, x, y;
    cin >> N;

 
    parent.resize(N + 1);
    depth.resize(N + 1, 0);
    for (size_t i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    vector<pair<size_t, size_t>> edgeList;
    while (cin >> x >> y) {
        edgeList.emplace_back(x, y);
    }

    size_t components = N;
    for (const auto& edge : edgeList) {
        x = edge.first;
        y = edge.second;

        size_t parentX = findParent(x);
        size_t parentY = findParent(y);

        if (parentX != parentY) {

            cout << components - 1 << endl;
            unionV(parentX, parentY);
            components--;
        } else {
           
            cout << components << " CYCLE FORMED!" << endl;
        }
    }

    return 0;
}
