class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].emplace_back(v, w);
        }
        
        vector<int> dist(n + 1, numeric_limits<int>::max()); 
        dist[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, k);
        
    
        while (!pq.empty()) {
            auto [currentDist, u] = pq.top();
            pq.pop();
            
            if (currentDist > dist[u]) continue; 
            
            for (const auto& [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        
        int maxDelay = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == numeric_limits<int>::max()) return -1;
            maxDelay = max(maxDelay, dist[i]);
        }
        
        return maxDelay;
    }
};
