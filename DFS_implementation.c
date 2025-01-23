#include <stdio.h>
#include "graph.h"

void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int vertices = 13;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 3, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 5, 7);
    addEdge(graph, 5, 9);
    addEdge(graph, 6, 8);
    addEdge(graph, 7, 10);
    addEdge(graph, 8, 10);
    addEdge(graph, 9, 11);
    addEdge(graph, 10, 12);
    addEdge(graph, 11, 12);

    printf("The following is the Depth First Traversal starting from vertex 1: \n");

    DFS(graph, 1);
    return 0;
}
