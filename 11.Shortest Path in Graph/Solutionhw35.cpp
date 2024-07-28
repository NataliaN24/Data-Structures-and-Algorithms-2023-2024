#include <iostream>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

const size_t MAX_SIZE = 1e4 + 1;

struct Stop {
    size_t interval;
};

Stop stops[MAX_SIZE];
unordered_map<size_t, std::unordered_map<size_t, size_t>> graph;

int shortestTime(size_t total, size_t start, size_t end) {
    size_t times[MAX_SIZE];
    for (size_t i = 0; i < total; i++) {
        times[i] = INT_MAX;
    }

    times[start] = 0;

    set<std::pair<size_t, size_t>> pq;
    pq.insert({ 0, start });

    while (!pq.empty()) {
        auto current = *pq.begin();
        pq.erase(current);

        if (current.second == end) {
            return times[current.second];
        }

        for (auto& next : graph[current.second]) {
            size_t remain = current.first % stops[current.second].interval;
            size_t newTime = current.first + next.second;

            if (remain != 0) {
                newTime += (stops[current.second].interval - remain);
            }

            if (times[next.first] > newTime) {
                pq.erase({ times[next.first], next.first });
                times[next.first] = newTime;
                pq.insert({ times[next.first], next.first });
            }
        }
    }

    return -1;
}

int main() {
    size_t totalStops, totalRoutes, start, end;
    cin >> totalStops >> totalRoutes >> start >> end;

    for (size_t i = 0; i < totalStops; i++) {
        cin >> stops[i].interval;
    }

    size_t from, to, distance;
    for (size_t i = 0; i < totalRoutes; i++) {
        cin >> from >> to >> distance;

        if (graph[from][to] == 0) {
            graph[from][to] = INT_MAX;
        }

        graph[from][to] = min(distance, graph[from][to]);
    }

    cout << shortestTime(totalStops, start, end);

    return 0;
}
