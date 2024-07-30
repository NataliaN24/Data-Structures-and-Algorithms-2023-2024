#include <iostream>
#include <vector>
#include <queue>
#include <utility> 
#include <climits> 

using namespace std;

struct Edge
{
	int vertex;
	int weight;
};

void PrimMST(const vector<vector<Edge>>& graph, int start)
{
	int n = graph.size();
	vector<int>key(n, INT_MAX);// Used to store the minimum weight to add a node to the MST
	vector<int>parent(n, -1);//Used to store MST
	vector<bool>inMST(n, false);//To check if vertex is already included in MST

	// Priority queue to pick the minimum weight edge at each step
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	pq.push({ 0,start });
	key[start] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		inMST[u] = true;


		for (const Edge& edge : graph[u])
		{
			int v = edge.vertex;
			int weight = edge.weight;

			// If v is not in MST and weight of u-v is smaller than current key of v
			if (!inMST[v] && key[v] > weight)
			{
				key[v] = weight;
				pq.push({ key[v],v });
				parent[v] = u;
			}
		}
	}
	cout << "Edges in the MST:" << endl;
	for (int i = 0; i < n; ++i) {
		if (parent[i] != -1) {
			cout << parent[i] << " - " << i << " with weight " << key[i] << endl;
		}
	}
}

int main() {
	int n, m; 
	cout << "Enter the number of vertices and edges:" << endl;
	cin >> n >> m;

	vector<vector<Edge>> graph(n);

	cout << "Enter the edges (u, v, weight):" << endl;
	for (int i = 0; i < m; ++i) {
		int u, v, weight;
		cin >> u >> v >> weight;
		graph[u].push_back({ v, weight });
		graph[v].push_back({ u, weight }); 
	}

	int start;
	cout << "Enter the starting vertex:" << endl;
	cin >> start;

	PrimMST(graph, start);

	return 0;
}