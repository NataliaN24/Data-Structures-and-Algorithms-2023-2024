#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

bool isRouteValid(const vector<long long>& route, 
                  const unordered_map<long long, unordered_map<long long, vector<long long>>>& graph, 
                  const unordered_set<long long>& superstitiousNumbers) {
    for (size_t i = 0; i < route.size() - 1; ++i) {
        long long start = route[i];
        long long end = route[i + 1];
        bool edgeFound = false;

        if (graph.find(start) != graph.end() && graph.at(start).find(end) != graph.at(start).end()) {
            for (const auto& weight : graph.at(start).at(end)) {
                if (superstitiousNumbers.find(weight) == superstitiousNumbers.end()) {
                    edgeFound = true;
                    break;
                }
            }
        }

        if (!edgeFound) {
            return false;
        }
    }
    return true;
}

int main() {
    long long V, E;
    cin >> V >> E;

    unordered_map<long long, unordered_map<long long, vector<long long>>> graph;
    unordered_set<long long> superstitiousNumbers;

    for (long long i = 0; i < E; ++i) {
        long long u, v, w;
        cin >> u >> v >> w;
        graph[u][v].push_back(w);
    }

    long long numSuperstitious;
    cin >> numSuperstitious;
    for (long long i = 0; i < numSuperstitious; ++i) {
        long long number;
        cin >> number;
        superstitiousNumbers.insert(number);
    }

    long long numRequests;
    cin >> numRequests;
    string result;

    for (long long i = 0; i < numRequests; ++i) {
        long long routeLength;
        cin >> routeLength;
        vector<long long> route(routeLength);
        for (long long j = 0; j < routeLength; ++j) {
            cin >> route[j];
        }

        if (isRouteValid(route, graph, superstitiousNumbers)) {
            result += '1';
        } else {
            result += '0';
        }
    }

    cout << result << endl;

    return 0;
}
