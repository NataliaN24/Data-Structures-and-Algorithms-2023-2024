#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, vector<int>>graph;
vector<int>component;
int currentComponent = 0;

void bfs(int start) {
    queue<int>q;
    q.push(start);
    component[start] = currentComponent;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int n : graph[node]) {
            if (component[n] == -1) {
                component[n] = currentComponent;
                q.push(n);
            }
        }
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    component.resize(v + 1, -1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }
    for (int i = 1; i <= v; i++) {
        if (component[i] == -1) {
            bfs(i);
            currentComponent++;
        }
    }
    int q;
    cin >> q;
    vector<int>result;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (component[a] == component[b]) {
            result.push_back(1);
        }
        else {
            result.push_back(0);
        }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}
