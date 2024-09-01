#include <iostream>
#include <vector>

struct Node
{
    int id;
    std::vector<Node *> neighbors;
    
    Node(int id) : id(id) {}
};

class Graph
{
  private:
    std::vector<Node *> nodes;

  public:
    void addNode(int id)
    {
        Node *newNode = new Node(id);
        nodes.push_back(newNode);
    }

    void addEdge(int id1, int id2)
    {
        Node *node1 = getNodeById(id1);
        Node *node2 = getNodeById(id2);
        if (node1 && node2)
        {
            node1->neighbors.push_back(node2);
            node2->neighbors.push_back(node1);
        }
    }

    Node *getNodeById(int id)
    {
        for (Node *node : nodes)
        {
            if (node->id == id)
            {
                return node;
            }
        }
        return nullptr;
    }

    void printGraph()
    {
        for (Node *node : nodes)
        {
            std::cout << "Node " << node->id << " -> ";
            for (Node *neighbor : node->neighbors)
            {
                std::cout << neighbor->id << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Graph()
    {
        for (Node *node : nodes)
        {
            delete node;
        }
    }
};

int main()
{
    Graph g;

    g.addNode(0);
    g.addNode(1);
    g.addNode(2);
    g.addNode(3);
    g.addNode(4);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
