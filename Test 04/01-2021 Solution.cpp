#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Request {
    int arrivalTime;
    int durationTime;
    Request(int arrival, int processing) : arrivalTime(arrival), durationTime(processing) {}
};

struct Compare {
    bool operator()(const Request &r1, const Request &r2) {
        return r1.durationTime > r2.durationTime;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }

    priority_queue<Request, vector<Request>, Compare> pq;

    int currentTime = 0;
    int minWait = INT_MAX;
    int maxWait = 0;

    pq.push(Request(0, times[0]));
    int index = 1;

    while (!pq.empty()) {
        Request current = pq.top();
        pq.pop();

        int start = max(currentTime, current.arrivalTime);
        int totalWaitTime = start - current.arrivalTime + current.durationTime;

        minWait = min(minWait, totalWaitTime);
        maxWait = max(maxWait, totalWaitTime);

        currentTime = start + current.durationTime;

        while (index < n && index <= currentTime) {
            pq.push(Request(index, times[index]));
            ++index;
        }
    }

    cout << minWait << " " << maxWait << endl;

    return 0;
}
