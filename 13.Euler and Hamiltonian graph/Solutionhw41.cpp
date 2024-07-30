//it doesn't cover all the edge cases
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

  
    unordered_map<int, int> divisorCount;

    for (int i = 0; i < N; ++i) {
        for (int j = 1; j * j <= nums[i]; ++j) {
            if (nums[i] % j == 0) {
                divisorCount[j]++;
                if (j != nums[i] / j) {
                    divisorCount[nums[i] / j]++;
                }
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        int l, r, d;
        cin >> l >> r >> d;

        int result = 0;
        for (int j = l - 1; j < r; ++j) {
            if (nums[j] % d == 0 || d % nums[j] == 0) {
                result++;
            }
        }

        cout << result << " ";
    }

    return 0;
}
