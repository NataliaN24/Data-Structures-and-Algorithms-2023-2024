#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#include <list>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    list<int> myList;
    int numberOfRequests;
    cin >> numberOfRequests;
    string request;
    int num;

    do {
        cin >> request;
        if (request == "add") {
            cin >> num;
            myList.push_back(num);
        } else if (request == "gun") {
            if (!myList.empty()) {
                myList.pop_back();
            }
        } else if (request == "milen") {
            if (!myList.empty()) {
                auto slow = myList.begin();
                auto fast = myList.begin();

                while (fast != myList.end() && next(fast) != myList.end()) {
                    advance(fast, 2);
                    advance(slow, 1);
                }

                myList.splice(myList.end(), myList, myList.begin(), slow);
            }
        }
        numberOfRequests--;
    } while (numberOfRequests != 0);

    cout << myList.size() << endl;

    for (const auto &val : myList) {
        cout << val << " ";
    }

    return 0;
}
//three tests didn't pass due to timeout error
