#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int u;
	int v;
	int weight;
	bool operator<(const Edge& other)const
	{
		return weight < other.weight;
	}
};

class DisjointSet
{
	vector<int>parent;
	vector<int>rank;
public:
	DisjointSet(int n)
	{
		parent.resize(n);
		rank.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			parent[i] = i;
		}
	}
	int find(int u)
	{
		if (parent[u] != u)
		{
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}
	void unionSets(int u, int v)
	{
		int rootU = find(u);
		int rootV = find(v);
		if (rootU != rootV)
		{
			if (rank[rootU] < rank[rootV])
			{
				parent[rootU] = rootV;
			}
			else if (rank[rootU] > rank[rootV])
			{
				parent[rootV] = rootU;
			}
			else 
			{
				parent[rootV] = rootU;
				rank[rootU]++;

			}
		}
	}
};

void KruskalMST(vector<Edge>& edges, int n)
{
	sort(edges.begin(), edges.end());
	DisjointSet ds(n);
	vector<Edge>mst;

	for (const Edge& e : edges)
	{
		if (ds.find(e.u) != ds.find(e.v))
		{
			mst.push_back(e);
			ds.unionSets(e.u, e.v);
		}
	}
	cout << "Edges in the MST:" << endl;
	for (const Edge& e : mst)
	{
		cout << e.u << " - " << e.v << " with weight" << e.weight << endl;
	}

}

int main() {
	int n, m;
	cout << "Enter the number of vertices and edges:" << endl;
	cin >> n >> m;

	vector<Edge> edges(m);

	cout << "Enter the edges (u, v, weight):" << endl;
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].u >> edges[i].v >> edges[i].weight;
	}

	KruskalMST(edges, n);

	return 0;
}