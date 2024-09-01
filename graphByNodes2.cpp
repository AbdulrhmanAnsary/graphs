#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int vertex;
    struct Node *next;
};

struct Graph
{
    int numVertices;
    struct Node **adjLists;
};

struct Node *createNode(int vertex)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // التحويل إلى struct Node*
    if (!newNode)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph)); // التحويل إلى struct Graph*
    if (!graph)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    graph->numVertices = numVertices;
    graph->adjLists = (struct Node **)malloc(numVertices * sizeof(struct Node *)); // التحويل إلى struct Node**
    if (!graph->adjLists)
    {
        fprintf(stderr, "Memory allocation error\n");
        free(graph);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numVertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        printf("\n Vertex %d:\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void freeGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct Node *temp = graph->adjLists[v];
        while (temp)
        {
            struct Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->adjLists);
    free(graph);
}

int main()
{
    struct Graph *graph = createGraph(5);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    printGraph(graph);

    freeGraph(graph);

    return 0;
}