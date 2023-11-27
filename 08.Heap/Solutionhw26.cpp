#include <iostream>
#include <vector>
#include <queue>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.first > b.first) return true;
    if (a.first == b.first && a.second > b.second) return true;
    return false;
}

bool busTravel(std::vector<std::vector<int>>& trips, int capacity) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(&compare)> pq(&compare);
    for (size_t i = 0; i < trips.size(); i++) {
        pq.push(std::make_pair(trips[i][1], trips[i][0]));
        pq.push(std::make_pair(trips[i][2], -trips[i][0]));
    }
    int ans = 0;
    while (!pq.empty()) {
        std::pair<int, int> a = pq.top();
        pq.pop();
        ans += a.second;
        if (ans > capacity) return false;
    }
    return true;
}

int main() {
    int requests;
    std::cin >> requests;

    while (requests--) {
        int groups, capacity;
        std::cin >> groups >> capacity;

        std::vector<std::vector<int>> trips(groups, std::vector<int>(3));
        for (int i = 0; i < groups; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cin >> trips[i][j];
            }
        }

        int result = busTravel(trips, capacity);
        std::cout << result << std::endl;
    }

    return 0;
}
