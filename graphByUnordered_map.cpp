#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>

class Graph
{
  private:
    std::unordered_map<int, std::list<int>> adjList;

  public:
    void addEdge(int u, int v, bool bidirectional = true)
    {
        adjList[u].push_back(v);
        if (bidirectional)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto &pair : adjList)
        {
            std::cout << pair.first << " -> ";
            for (int node : pair.second)
            {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printAdjList();

    return 0;
}