#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int node, vector<vector<int>>& adj_list, unordered_set<int>& visited) {
    visited.insert(node);

    for (int neighbor : adj_list[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, adj_list, visited);
        }
    }
}

int countDistricts(int num_cities, vector<pair<int, int>>& roads) {
    vector<vector<int>> adj_list(num_cities);

   
    for (const auto& road : roads) {
        int city1 = road.first;
        int city2 = road.second;
        adj_list[city1].push_back(city2);
        adj_list[city2].push_back(city1);
    }

    int districts = 0;
    unordered_set<int> visited;

    for (int i = 0; i < num_cities; ++i) {
        if (visited.find(i) == visited.end()) {
            
            districts++;
            dfs(i, adj_list, visited);
        }
    }

    return districts;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int X, Y;
        cin >> X >> Y;

        vector<pair<int, int>> roads;

        for (int i = 0; i < Y; ++i) {
            int x, y;
            cin >> x >> y;
            roads.push_back({x, y});
        }

        int result = countDistricts(X, roads);
        cout << result << " ";
    }

    return 0;
}
