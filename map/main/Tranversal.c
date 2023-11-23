#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void depthFirstTraversal(Graph* graph, int vertex, int* visited) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    ListNode* curr = graph->adjList[vertex];
    while (curr != NULL) {
        if (!visited[curr->vertex]) {
            depthFirstTraversal(graph, curr->vertex, visited);
        }
        curr = curr->next;
    }
}

void breadthFirstTraversal(Graph* graph, int startVertex) {
    int* visited = (int*)calloc(graph->numVertices, sizeof(int));
    int* queue = (int*)malloc(graph->numVertices * sizeof(int));
    int front = 0;
    int rear = -1;

    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    printf("广度优先遍历：\n");
    while (front <= rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        ListNode* curr = graph->adjList[vertex];
        while (curr != NULL) {
            if (!visited[curr->vertex]) {
                visited[curr->vertex] = 1;
                queue[++rear] = curr->vertex;
            }
            curr = curr->next;
        }
    }

    printf("\n");

    free(visited);
    free(queue);
}

