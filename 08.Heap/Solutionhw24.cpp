
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> ClosestLandmarks(vector<vector<int>>& points, int k, int x, int y) {
    vector<vector<int>> ans;
    priority_queue<pair<double, vector<int>>> pq;

    for (size_t i = 0; i < points.size(); i++) {
        double distance = sqrt(pow(points[i][0] - x, 2) + pow(points[i][1] - y, 2));
        pq.push({ distance, points[i] });
        if (pq.size() > static_cast<size_t>(k)) {
            pq.pop();
        }
    }

    while (!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int currentx, currenty, totalsights, K;
    cin >> currentx >> currenty >> totalsights >> K;

    vector<vector<int>> sights(totalsights, vector<int>(2));
    for (int i = 0; i < totalsights; ++i) {
        cin >> sights[i][0] >> sights[i][1];
    }

    vector<vector<int>> closestSights = ClosestLandmarks(sights, K, currentx, currenty);

    for (const auto& sight : closestSights) {
        cout << sight[0] << " " << sight[1] << endl;
    }

    return 0;
}
