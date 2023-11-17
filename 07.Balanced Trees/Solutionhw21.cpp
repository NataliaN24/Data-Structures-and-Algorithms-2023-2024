
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<pair<int, int>> findSubArrays(int arr[], int n) {
    unordered_map<int, vector<int>> map;
    vector<pair<int, int>> out;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            out.push_back(make_pair(0, i));
        }

        if (map.find(sum) != map.end()) {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++) {
                out.push_back(make_pair(*it + 1, i));
            }
        }

        map[sum].push_back(i);
    }

    return out;
}

int main() {
    int n, B;

    cin >> n >> B;
    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < B) {
            arr[i] = -1;
        }
        else if (arr[i] > B) {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }

    vector<pair<int, int>> result = findSubArrays(arr, n);

    int count = 0;
    for (size_t i = 0; i < result.size(); i++) {
        pair<int, int> subArray = result[i];
        int length = subArray.second - subArray.first + 1;
        if (length % 2 != 0) { 
            bool containsB = false;
            for (int j = subArray.first; j <= subArray.second; j++) {
                if (arr[j] == 0) { 
                    containsB = true;
                    break;
                }
            }
            if (containsB) {
                count++;
            }
        }
    }

    cout << count << endl;

    delete[] arr; 
    return 0;
}
