#ifndef _GRAPH_H_
#define _GRAPH_H_


typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

Graph* createGraph(int vertices);
Node* createNode(int v);
void addEdge(Graph* graph, int src, int dest);

#endif

