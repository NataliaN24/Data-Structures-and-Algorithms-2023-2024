#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void dfs(unordered_map<char, unordered_set<char>>& graph, unordered_map<char, bool>& visited, char c, vector<char>& order) {
    visited[c] = true;

    for (char nearNeighbor : graph[c]) {
        if (!visited[nearNeighbor]) {
            dfs(graph, visited, nearNeighbor, order);
        }
    }

    order.push_back(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    unordered_map<char, unordered_set<char>> graph;
    for (int i = 0; i < n - 1; ++i) {
        int len = min(words[i].size(), words[i + 1].size());
        for (int j = 0; j < len; ++j) {
            if (words[i][j] != words[i + 1][j]) {
                graph[words[i][j]].insert(words[i + 1][j]);
                graph[words[i + 1][j]];
                break;
            }
        }
    }

    unordered_map<char, bool> visited;
    vector<char> order;

    for (const auto& entry : graph) {
        visited[entry.first] = false;
    }


    for (const auto& entry : graph) {
        if (!visited[entry.first]) {
            dfs(graph, visited, entry.first, order);
        }
    }

    reverse(order.begin(), order.end());

    for (char c : order) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
