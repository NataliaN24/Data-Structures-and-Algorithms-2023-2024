#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

bool isSymmetric(vector<long long>& arr)
{
    stack<long long>positive;

    for (long long num : arr) {
        if (num >= 0) {
            positive.push(num);
        }
        else if (num < 0) {
            if (!positive.empty()) {
                long long positiveNumber = positive.top();

                if (-positiveNumber == num) {
                    positive.pop();
                }
                else {
                    return false;
                    break;
                }
            }
            else {
                return false;
                break;
            }
        }

    }
    return positive.empty();

}

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<long long >arr(k);
        for (int j = 0; j < k; j++) {
            cin >> arr[j];
        }
        if (isSymmetric(arr)) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
