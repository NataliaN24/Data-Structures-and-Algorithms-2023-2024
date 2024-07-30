#include <iostream>
#include <vector>
#include <algorithm>

struct Road {
    size_t start, end;
    long long cost;

    bool operator<(const Road &other) const {
        return this->start < other.start || (this->start == other.start && this->cost > other.cost);
    }
};

const size_t MAX_NODES = 2 * 1e5 + 5;
std::vector<std::pair<Road, std::pair<size_t, size_t>>> graph;
size_t ancestors[MAX_NODES];

size_t findIntersection(const size_t node) {
    if (node == ancestors[node]) {
        return node;
    }
    ancestors[node] = findIntersection(ancestors[node]);
    return ancestors[node];
}

void connectIntersections(const size_t &from, const size_t &to) {
    ancestors[from] = ancestors[to];
}

void minimalSpanningTree() {
    size_t intersectionA, intersectionB;
    std::sort(graph.begin(), graph.end());
    for (size_t i = 0; i < graph.size(); i++) {
        intersectionA = findIntersection(graph[i].second.first);
        intersectionB = findIntersection(graph[i].second.second);
        if (intersectionA != intersectionB) {
            std::cout << graph[i].first.end << '\n';
            connectIntersections(intersectionA, intersectionB);
        }
    }
}

int main() {
    size_t totalIntersections, totalRoads, from, to, effort;
    long long price;
    std::cin >> totalIntersections >> totalRoads;
    for (size_t i = 0; i < totalRoads; ++i) {
        std::cin >> from >> to >> effort >> price;
        graph.push_back({{effort, i + 1, price},
                         {from, to}});
    }

    for (size_t i = 0; i < totalIntersections; ++i) {
        ancestors[i] = i;
    }

    minimalSpanningTree();

    return 0;
}
