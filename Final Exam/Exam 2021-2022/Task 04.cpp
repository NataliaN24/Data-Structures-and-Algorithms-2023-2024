#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

size_t minSeconds = 0;

bool check(vector <size_t>& arr, size_t seconds, size_t target) {
    size_t pancakes = 0;
    for (const auto& element : arr) {
        pancakes += seconds / element;
        if (pancakes >= target) {
            return true;
        }
    }

    return false;
}

void binarySearch(vector <size_t>& arr, size_t left, size_t right, size_t target) {
    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (check(arr, mid, target)) {
            right = mid - 1;
            minSeconds = mid;
        }
        else {
            left = mid + 1;
        }
    }
}

int main() {
    size_t N, K;
    cin >> N >> K;
    vector <size_t> chefs(K);

    for (size_t i = 0; i < K; ++i) {
        cin >> chefs[i];
    }
    sort(chefs.begin(), chefs.end());
    binarySearch(chefs, chefs[0], chefs[0] * N, N);
    cout << minSeconds;
    return 0;
}
