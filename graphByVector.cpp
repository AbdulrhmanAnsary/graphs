#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph
{
  public:
    int numVertices;
    vector<list<int>> adjLists;

    Graph(int vertices);
    void addEdge(int src, int dest);
    void printGraph();
};

Graph::Graph(int vertices) : numVertices(vertices), adjLists(vertices) {}

void Graph::addEdge(int src, int dest)
{
    adjLists[src].push_back(dest);
    adjLists[dest].push_back(src);
}

void Graph::printGraph()
{
    for (int v = 0; v < numVertices; ++v)
    {
        cout << "\n Vertex " << v << ":\n ";
        for (auto x : adjLists[v])
            cout << x << " -> ";
        cout << "NULL\n";
    }
}

int main()
{
    Graph graph(5);

    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.printGraph();

    return 0;
}
