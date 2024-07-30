#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

struct Link {
    size_t start;
    size_t end;
    size_t value;

    bool operator<(const Link &other) const {
        return value < other.value;
    }
};

constexpr size_t calculateMaxNodes() {
    return 10005;
}

std::vector<Link> connections(calculateMaxNodes());
std::vector<size_t> parents(calculateMaxNodes());

size_t findRoot(size_t v, std::vector<size_t>& parents) {
    if (v == parents[v])
        return v;

    return parents[v] = findRoot(parents[v], parents);
}

bool uniteNodes(size_t from, size_t to, std::vector<size_t>& parents) {
    size_t rootA = findRoot(from, parents);
    size_t rootB = findRoot(to, parents);

    parents[rootB] = rootA;
    return rootA != rootB;
}

void initializeParents(std::vector<size_t>& parents) {
    for (size_t i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }
}

std::pair<size_t, size_t> findMinMaxTree(size_t totalNodes, size_t totalLinks, std::vector<Link>& connections, std::vector<size_t>& parents) {
    std::sort(connections.begin(), connections.begin() + totalLinks, std::less<Link>());

    size_t minVal = 0;
    size_t maxVal = ULLONG_MAX;

    for (size_t i = 0; i < totalLinks; ++i) {
        initializeParents(parents);

        size_t count = 0;
        size_t currentMin = connections[i].value;
        size_t currentMax = connections[i].value;
        size_t valueDiff = maxVal - minVal;

        for (size_t j = i; j < totalLinks; ++j) {
            if (uniteNodes(connections[j].start, connections[j].end, parents)) {
                count++;
                currentMax = std::max(currentMax, connections[j].value);
            }

            if (valueDiff <= currentMax - currentMin)
                break;
        }

        if (count == totalNodes - 1 && valueDiff > currentMax - currentMin) {
            minVal = currentMin;
            maxVal = currentMax;
        }
    }

    return {minVal, maxVal};
}

int main() {
    size_t vertices, edges;
    std::cin >> vertices >> edges;

    std::vector<Link> connections(edges);
    for (size_t i = 0; i < edges; ++i) {
        size_t from, to, weight;
        std::cin >> from >> to >> weight;
        connections[i] = {from, to, weight};
    }

    auto result = findMinMaxTree(vertices, edges, connections, parents);

    std::cout << result.first << " " << result.second;

    return 0;
}
