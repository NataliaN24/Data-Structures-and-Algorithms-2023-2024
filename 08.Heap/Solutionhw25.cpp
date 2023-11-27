
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int ChairOccupied(vector<vector<int>>& times, int targetFriend) {
    int target = times[targetFriend][0];

    sort(times.begin(), times.end());
    int n = times.size();

    priority_queue<int, vector<int>, greater<int>> a;

    for (int i = 0; i < n; i++)
        a.push(i);


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leaving;

    for (auto v : times) {
        int arrival = v[0], departure = v[1];
        while (!leaving.empty() && leaving.top().first <= arrival) {
            pair<int, int> p = leaving.top();
            leaving.pop();
            a.push(p.second);
        }
        int chair = a.top();
        a.pop();
        leaving.push({ departure, chair });
        if (arrival == target)
            return chair;
    }
    return -1;
}

int main() {
    int numFriends;
    cin >> numFriends;

    vector<vector<int>> times(numFriends, vector<int>(2));
    for (int i = 0; i < numFriends; ++i) {
        cin >> times[i][0] >> times[i][1];
    }

    int targetFriend;
    cin >> targetFriend;

    int chair = ChairOccupied(times, targetFriend);
    cout << chair << endl;

    return 0;
}
