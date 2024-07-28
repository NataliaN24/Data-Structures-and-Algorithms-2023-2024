#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph
{
	int  V;
	vector<list<int>>adjList;
public:
	Graph(int V);
	void addEdge(int v, int w);
	vector<int>adj(int v);
	int vertices()const ;
};

Graph::Graph(int V)
{
	this->V = V;
	adjList.resize(V);
}

void Graph::addEdge(int v, int w)
{
	adjList[v].push_back(w);
	//за ненасочен граф имаме и че :adjList[w].push_back(v);
}

vector<int> Graph::adj(int v)
{
	vector<int>neighbors;
	for (int neighbor : adjList[v]) {
		neighbors.push_back(neighbor);
	}
	return neighbors;
}

int Graph::vertices()const
{
	return V;
}

int main() {
    Graph g(5);

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