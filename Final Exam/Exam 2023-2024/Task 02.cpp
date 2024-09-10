#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findClosestIndex(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}


vector<int> processQueries(const vector<int>& arr, const vector<int>& queries) {
    vector<int> results;
    int n = arr.size();

    for (int query : queries) {
        int idx = findClosestIndex(arr, query);

        int closest;
        if (idx == -1) {
            closest = arr[0];
        }
        else if (idx == n - 1) {
            closest = arr[n - 1];
        }
        else {
            int left = arr[idx];
            int right = arr[idx + 1];
            if (abs(left - query) < abs(right - query)) {
                closest = left;
            }
            else if (abs(left - query) > abs(right - query)) {
                closest = right;
            }
            else {
                closest = max(left, right);
            }
        }

        auto closest_it = lower_bound(arr.begin(), arr.end(), closest, greater<int>());
        int closest_idx = distance(arr.begin(), closest_it);
        if (closest_idx == 0) {
            results.push_back(-1);
        }
        else {
            results.push_back(arr[closest_idx - 1]);
        }
    }

    return results;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i];
    }

    vector<int> results = processQueries(arr, queries);
    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}
