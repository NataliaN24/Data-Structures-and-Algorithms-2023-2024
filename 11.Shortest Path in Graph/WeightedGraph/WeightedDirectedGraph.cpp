#include <iostream>
#include <vector>
using namespace std;

class WeightedEdge
{
	int v, u, w;

public:
	WeightedEdge(int from,int to,int weight):v(from),u(to),w(weight){}
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

WeightedDirectedGraph::WeightedDirectedGraph(int v):numVertices(v),adjList(new vector<WeightedEdge>[v]){}

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

int main() {
	WeightedDirectedGraph g(5); 

	g.addEdge(WeightedEdge(0, 1, 10));
	g.addEdge(WeightedEdge(0, 4, 20));
	g.addEdge(WeightedEdge(1, 2, 30));
	g.addEdge(WeightedEdge(1, 3, 40));
	g.addEdge(WeightedEdge(2, 3, 50));
	g.addEdge(WeightedEdge(3, 4, 60));


	for (int i = 0; i < g.vertices(); ++i) {
		cout << "Edges from vertex " << i << ":" << endl;
		vector<WeightedEdge> edges = g.adj(i);
		for ( auto& edge : edges) {
			cout << "To vertex " << edge.to() << " with weight " << edge.weight() << endl;
		}
		cout << endl;
	}

	return 0;
}
