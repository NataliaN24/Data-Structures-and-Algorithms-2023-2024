#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_map<int, std::vector<int>> topics;
    for (int i = 0; i < N; ++i) {
        int topic;
        cin >> topic;
        topics[topic].push_back(i);
    }

    int theleastdist = INT_MAX;

    for (auto& topic : topics) {
        vector<int>& grannny = topic.second;
        int size = grannny.size();
        for (int i = 0; i < size - 1; ++i) {
            theleastdist = std::min(theleastdist, grannny[i + 1] - grannny[i]);
        }
    }

    cout << theleastdist << endl;

    return 0;
}
