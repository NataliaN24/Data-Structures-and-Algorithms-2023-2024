#include <iostream>
#include <vector>

using namespace std;

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
	void print()
	{
		cout << "Disjoint Set Structure:" << endl;
		for (int i = 0; i < parent.size(); i++)
		{
			cout << i << "->" << find(i) << endl;
		}

	}
};

int main() {
	int n = 5; 
	DisjointSet ds(n);


	ds.unionSets(0, 1);
	ds.unionSets(1, 2);
	ds.unionSets(3, 4);

	
	cout << "Find(2): " << ds.find(2) << endl;
	cout << "Find(4): " << ds.find(4) << endl;

	ds.print();

	return 0;
}