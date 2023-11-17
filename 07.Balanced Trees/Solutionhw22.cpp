
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> nums(M);
    unordered_set<int> Set;

    for (int i = 0; i < M; ++i) {
        cin >> nums[i];
        Set.insert(nums[i]);
    }

    vector<int> result;
    for (int i = 1; i <= N; ++i) {
        if (Set.find(i) == Set.end()) {
            result.push_back(i);
        }
    }

    vector<int> res;
    int j = 0;
    for (int i = 0; i < M; ++i) {
        while (j < static_cast<int>(result.size()) && result[j] < nums[i]) {
            res.push_back(result[j]);
            ++j;
        }
        res.push_back(nums[i]);
    }

    while (j < static_cast<int>(result.size())) {
        res.push_back(result[j]);
        ++j;
    }

    for (int i = 0; i < N; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
