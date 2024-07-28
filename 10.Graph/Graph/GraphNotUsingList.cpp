#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
    int numVertices;
    vector<int>* adjList;
    bool directed;

public:
	Graph(int V,bool directed);
	void addEdge(int v, int w);
	vector<int>adj(int v);
	int vertices()const ;
    ~Graph();
};

Graph::Graph(int V, bool directed)
{
    numVertices = V;
    adjList = new vector<int>[V];
    this->directed = directed;

}

void Graph::addEdge(int v, int w)
{
    adjList[v].push_back(w);
    if (!directed)
    {
        adjList[w].push_back(v);
    }
}

vector<int> Graph::adj(int v)
{
    return adjList[v];
}

int Graph::vertices()const
{
    return numVertices;
}

Graph::~Graph()
{
    delete[]adjList;
}

int main() {
    Graph g(5, false); 

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Number of vertices: " << g.vertices() << endl;

    for (int v = 0; v < g.vertices(); ++v) {
        vector<int> neighbors = g.adj(v);
        cout << "Neighbors of vertex " << v << ":";
        for (int neighbor : neighbors) {
            cout << " " << neighbor;
        }
        cout << endl;
    }

    return 0;
}