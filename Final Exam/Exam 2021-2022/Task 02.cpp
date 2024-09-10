#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

void bfs(const vector<vector<int>>& graph, int start, vector<int>& distances)
{
    int n = graph.size();
    vector<bool>visited(n, false);
    queue<int>q;
    q.push(start);
    distances[start] = 0;
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int n : graph[node])
        {
            if (!visited[n])
            {
                visited[n] = true;
                distances[n] = distances[node] + 6;
                q.push(n);
            }
        }
    }

}
int main() {
    int q;
    cin >> q;
    while (q--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>>graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int start;
        cin >> start;
        vector<int>distances(n + 1, INF);
        bfs(graph, start, distances);

        for (int i = 1; i <= n; i++)
        {
            if (i != start)
                if (distances[i] == INF)
                {
                    cout << -1 << " ";
                }
                else {
                    cout << distances[i] << " ";
                }

        }
        cout << endl;
    }
}