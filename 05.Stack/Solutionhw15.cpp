//all test passed
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> fight(std::vector<int>& a) {
    std::stack<int> pos;
    std::stack<int> neg;
    int n = a.size();

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > 0) {
            if (neg.empty()) {
                pos.push(a[i]);
            }
            else {
                while (!neg.empty() && (a[i] - std::abs(neg.top())) > 0) {
                    neg.pop();
                }

                if (neg.empty()) {
                    pos.push(a[i]);
                }
                else {
                    if (a[i] == std::abs(neg.top())) {
                        neg.pop();
                    }
                }
            }
        }
        else {
            neg.push(a[i]);
        }
        a.pop_back();
    }

    while (!neg.empty()) {
        a.push_back(neg.top());
        neg.pop();
    }
    while (!pos.empty()) {
        a.push_back(pos.top());
        pos.pop();
    }

    return a;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> fighters(n);
    for (int i = 0; i < n; i++) {
        std::cin >> fighters[i];
    }

    std::vector<int> result = fight(fighters);

    for (int i = 0; i < static_cast<int>(result.size()); i++) {
        std::cout << result[i];
        if (i < static_cast<int>(result.size()) - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
//one test didn't pass
#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    deque<long long> nums;

    for (int i = 0; i < n; i++) {
        long long strength;
        cin >> strength;

        if (nums.empty()) {
            nums.push_back(strength);
        } else {
            if ((strength < 0 && nums.back() == -strength)) {
                nums.pop_back();
            } else if (strength < 0 && nums.back() < 0) {
                nums.push_back(strength);
            } else if (strength > 0 && (nums.back() < 0 || nums.back() > 0)) {
                nums.push_back(strength);
            } else if (strength < 0 && nums.back() > 0) {
                while (!nums.empty() && abs(strength) > nums.back() && nums.back() > 0) {
                    nums.pop_back();
                }
                if (nums.empty() || (nums.back() < 0 && nums.back() != -strength)) {
                    nums.push_back(strength);
                }
            }
        }
    }

    vector<long long> fighters(nums.begin(), nums.end());

    for (int i = 0; i < static_cast<int>(fighters.size()); i++) {
        cout << fighters[i];
        if (i < static_cast<int>(fighters.size() - 1)) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
