#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

void BFS(Graph* graph, int startVertex) {
    int* visited = malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    int queue[100], front = 0, rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("Visited %d\n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }

            temp = temp->next;
        }
    }

    free(visited);
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

    printf("BFS Traversal\n");
    BFS(graph, 1);

    return 0;
}
