#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

void addMedian(int num, priority_queue<int>& maxheap, priority_queue<int, vector<int>, greater<int>>& minheap) {
    if (maxheap.empty() || num <= maxheap.top()) {
        maxheap.push(num);
    } else {
        minheap.push(num);
    }

    if (maxheap.size() > minheap.size() + 1) {
        minheap.push(maxheap.top());
        maxheap.pop();
    } else if (minheap.size() > maxheap.size()) {
        maxheap.push(minheap.top());
        minheap.pop();
    }

    double med;
    if (maxheap.size() > minheap.size()) {
        med = maxheap.top();
    } else {
        med = (maxheap.top() + minheap.top()) / 2.0;
    }
    cout << fixed << setprecision(1) << med << endl;
}

int main() {
    int n;
    cin >> n;

    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        addMedian(num, maxheap, minheap);
    }

    return 0;
}
