#include <iostream>
#include <vector>
#include <climits> 
#include <queue>
using namespace std;
typedef pair<int, int>iPair; // Pair of (distance, vertex)

class WeightedEdge
{
	int v, u, w;

public:
	WeightedEdge(int from, int to, int weight) :v(from), u(to), w(weight) {}
	int from() {
		return v;
	}
	int to() {
		return u;
	}
	int weight() {
		return w;
	}
};

class WeightedDirectedGraph
{
	int numVertices;
	vector< WeightedEdge>* adjList;

public:
	WeightedDirectedGraph(int v);
	void addEdge(WeightedEdge e);
	vector<WeightedEdge>adj(int v);
	int vertices();
	~WeightedDirectedGraph();

};

WeightedDirectedGraph::WeightedDirectedGraph(int v) :numVertices(v), adjList(new vector<WeightedEdge>[v]) {}

void WeightedDirectedGraph::addEdge(WeightedEdge e)
{
	adjList[e.from()].push_back(e);
}

vector<WeightedEdge> WeightedDirectedGraph::adj(int v)
{
	return adjList[v];
}

int WeightedDirectedGraph::vertices()
{
	return numVertices;
}

WeightedDirectedGraph::~WeightedDirectedGraph()
{
	delete[]adjList;
}

class ShortestPath
{
protected:
	WeightedDirectedGraph graph;
	int* distTo;
	int* edgeTo;

	bool relax(WeightedEdge e)
	{
		int v = e.from();
		int u = e.to();
		int weight = e.weight();
		int currentPathDistance = distTo[v] + e.weight();
		if (distTo[u] > currentPathDistance)
		{
			distTo[u] = currentPathDistance;
			edgeTo[u] = e.from();
			return true;
		}
		return false;
	}
public:
	ShortestPath(WeightedDirectedGraph graph, int from) :graph(graph)
	{
		distTo = new int[graph.vertices()];
		edgeTo = new int[graph.vertices()];
		for (int i = 0; i < graph.vertices(); i++) {
			distTo[i] = INT_MAX;
			edgeTo[i] = -1;
		}
		distTo[from] = 0;
		Dijkstra(from);
	}
	void Dijkstra(int from)
	{
		bool* visited = new bool[graph.vertices()];
		fill(visited, visited + graph.vertices(), false);
		priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
		pq.push({ 0, from });
		while (!pq.empty()) {
			int v = pq.top().second;
			pq.pop();
			if (visited[v]) {
				continue;
			}
			visited[v] = true;
			for (WeightedEdge e : graph.adj(v)) {
				if (relax(e)) {
					pq.push({ distTo[e.to()], e.to() });
				}
			}
		}
		delete[] visited;
	}

	void printShortestPath()
	{
		for (int v = 0; v < graph.vertices(); v++) {
			if (distTo[v] == INT_MAX)
			{
				cout << "Vertex " << v << " is not reachable from the source." << endl;
			}
			else {
				cout << "Distance to vertex " << v << " is " << distTo[v] << endl;

				cout << "Path: ";
				vector<int>path;
				for (int x = v; x != -1; x = edgeTo[x]) {
					path.push_back(x);
				}
				for (auto it = path.rbegin(); it != path.rend(); ++it)
				{
					cout << *it << " ";
				}
				cout << endl;
			}
		}
	}
	~ShortestPath() {
		delete[]distTo;
		delete[]edgeTo;
	}

};

int main() {
	WeightedDirectedGraph g(5);

	g.addEdge(WeightedEdge(0, 1, 10));
	g.addEdge(WeightedEdge(0, 4, 20));
	g.addEdge(WeightedEdge(1, 2, 30));
	g.addEdge(WeightedEdge(1, 3, 40));
	g.addEdge(WeightedEdge(2, 3, 50));
	g.addEdge(WeightedEdge(3, 4, 60));

	ShortestPath sp(g, 0);
	sp.printShortestPath();

	return 0;
}

