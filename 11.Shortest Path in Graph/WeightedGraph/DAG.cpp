﻿#include <iostream>
#include <vector>
#include <climits>
#include<stack>
using namespace std;

class WeightedEdge {
    int v, u, w;

public:
    WeightedEdge(int from, int to, int weight) : v(from), u(to), w(weight) {}
    int from() { return v; }
    int to() { return u; }
    int weight() { return w; }
};

class WeightedDirectedGraph {
    int numVertices;
    vector<WeightedEdge>* adjList;

public:
    WeightedDirectedGraph(int v);
    void addEdge(WeightedEdge e);
    vector<WeightedEdge> adj(int v);
    int vertices();
    ~WeightedDirectedGraph();
};

WeightedDirectedGraph::WeightedDirectedGraph(int v) : numVertices(v), adjList(new vector<WeightedEdge>[v]) {}

void WeightedDirectedGraph::addEdge(WeightedEdge e) {
    adjList[e.from()].push_back(e);
}

vector<WeightedEdge> WeightedDirectedGraph::adj(int v) {
    return adjList[v];
}

int WeightedDirectedGraph::vertices() {
    return numVertices;
}

WeightedDirectedGraph::~WeightedDirectedGraph() {
    delete[] adjList;
}

class ShortestPath {
protected:
    WeightedDirectedGraph graph;
    int* distTo;
    int* edgeTo;

    bool relax(WeightedEdge e) {
        int v = e.from();
        int u = e.to();
        int weight = e.weight();
        int currentPathDistance = distTo[v] + weight;
        if (distTo[u] > currentPathDistance) {
            distTo[u] = currentPathDistance;
            edgeTo[u] = v;
            return true;
        }
        return false;
    }
    void dfs(int v, bool* visited, stack<int>& topoOrder)
    {
        visited[v] = true;
        for (WeightedEdge e : graph.adj(v))
        {
            if (!visited[e.to()]) {
                dfs(e.to(), visited, topoOrder);
            }
        }
        topoOrder.push(v);
    }
    stack<int>topoSort()
    {
        stack<int>topoOrder;
        bool* visited = new bool[graph.vertices()];
        for (int i = 0; i < graph.vertices(); i++) {
            visited[i] = false;
        }
        for (int i = 0; i < graph.vertices(); i++) {
            if (!visited[i]) {
                dfs(i, visited, topoOrder);
            }
        }
        delete[] visited;
        return topoOrder;
    }
    
    void shortestPath()
    {
        stack<int>topoOrder = topoSort();
        while (!topoOrder.empty())
        {
            int v = topoOrder.top();
            topoOrder.pop();
            for (WeightedEdge e : graph.adj(v)) {
                relax(e);
            }
        }
    }

public:
    ShortestPath(WeightedDirectedGraph graph, int from) : graph(graph) {
        distTo = new int[graph.vertices()];
        edgeTo = new int[graph.vertices()];
        for (int i = 0; i < graph.vertices(); i++) {
            distTo[i] = INT_MAX;
            edgeTo[i] = -1;
        }
        distTo[from] = 0;
        shortestPath();
    }
    bool hasNegativeCycle()
    {
        for (int i = 0; i < graph.vertices(); i++) {
            for (WeightedEdge e : graph.adj(i)) {
                if (relax(e)) {
                    return true;
                }
            }
            return false;
        }
    }
    void printShortestPath() {
        for (int v = 0; v < graph.vertices(); v++) {
            if (distTo[v] == INT_MAX) {
                cout << "Vertex " << v << " is not reachable from the source." << endl;
            }
            else {
                cout << "Distance to vertex " << v << " is " << distTo[v] << endl;
                cout << "Path: ";
                vector<int> path;
                for (int x = v; x != -1; x = edgeTo[x]) {
                    path.push_back(x);
                }
                for (auto it = path.rbegin(); it != path.rend(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
        }
    }

    ~ShortestPath() {
        delete[] distTo;
        delete[] edgeTo;
    }
};

int main() {
    WeightedDirectedGraph g(6);

    g.addEdge(WeightedEdge(0, 1, 5));
    g.addEdge(WeightedEdge(0, 2, 3));
    g.addEdge(WeightedEdge(1, 3, 6));
    g.addEdge(WeightedEdge(1, 2, 2));
    g.addEdge(WeightedEdge(2, 4, 4));
    g.addEdge(WeightedEdge(2, 5, 2));
    g.addEdge(WeightedEdge(3, 5, 1));
    g.addEdge(WeightedEdge(4, 5, 7));

    ShortestPath sp(g, 0);
    sp.printShortestPath();

    return 0;
}
