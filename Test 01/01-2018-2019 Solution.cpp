
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for (int i = n - 1; i >= 0; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                found = true;
                break;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        cout << "true";
    } else {
        cout << "false";
    }

    delete[] arr;

    return 0;
}
