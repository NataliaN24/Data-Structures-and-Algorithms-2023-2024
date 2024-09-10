#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

unordered_map<size_t, vector<size_t>>graph;
unordered_map<size_t, bool>visited;
size_t counter = 0;

void dfs(size_t value) {
    visited[value] = true;
    counter++;
    for (const auto& el : graph[value]) {
        if (!visited[el]) {
            dfs(el);
        }
    }
}
size_t res = 0;

void traverse(size_t n, size_t k)
{
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            if (counter % k == 0) {
                res++;
            }
            counter = 0;
        }
    }

}

int main() {
    int n, m, k, from, to;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    traverse(n, k);
    cout << res;
    return 0;
}
