
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const long long INFINITY_DISTANCE = LLONG_MAX;

struct Tunnel {
    int _dest;
    int time;
    int loseWeight;

    Tunnel(int dest, int t, int weight) : _dest(dest), time(t), loseWeight(weight) {}
};

long long shortestTime(vector<vector<Tunnel>>& tunnels, int mid) {
    
    vector<long long> times(tunnels.size(), INFINITY_DISTANCE);
    int startNode = 1;
    int endNode = tunnels.size() - 1;
    times[startNode] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({ 0, startNode });
    vector<bool> visited(tunnels.size());

    while (!pq.empty()) {
        int current = pq.top().second;
        long long timeToCurrent = pq.top().first;
        pq.pop();

        if (visited[current]) {
            continue;
        }

        visited[current] = true;

        for (Tunnel tunnel : tunnels[current]) {
            if (tunnel.loseWeight > mid) {
                continue;
            }

            int node = tunnel._dest;
            long long currentTime = timeToCurrent + tunnel.time;

            if (currentTime < times[node]) {
                times[node] = currentTime;
                pq.push({ currentTime, node });
            }
        }
    }

    return times[endNode];
}

int binSearch(vector<vector<Tunnel>>& tunnels, int K, int maxLoss) {
    int left = 0;
    int right = maxLoss;
    int minWeightLoss = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long currShortTime = shortestTime(tunnels, mid);

        if (currShortTime <= K) {
            minWeightLoss = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return minWeightLoss;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<Tunnel>> tunnels(N + 1, vector<Tunnel>());
    int maxWeight = -1;

    for (int i = 0; i < M; ++i) {
        int u, v, c, t;
        cin >> u >> v >> c >> t;

        if (c > maxWeight) {
            maxWeight = c;
        }

        tunnels[u].push_back(Tunnel(v, t, c));
    }

    int minWeightLoss = binSearch(tunnels, K, maxWeight);
    cout << minWeightLoss;

    return 0;
}
