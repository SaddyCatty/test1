#include <stdio.h>
#include "graph.h"
int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 0);
    addEdge(graph, 2, 4);
    addEdge(graph, 2, 0);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 1);
    addEdge(graph, 4, 2);
    addEdge(graph, 5, 3);

    printAdjMatrix(graph);
    printf("Adjacency List:\n");
    printGraph(graph);

    printf("\nDFS traversal:\n");
    DFS(graph, 0);

    destroyGraph(graph);

    // 创建新的图并添加边
    Graph* newGraph = createGraph(vertices);
    addEdge(newGraph, 0, 2);
    addEdge(newGraph, 0, 1);
    addEdge(newGraph, 1, 3);
    addEdge(newGraph, 1, 0);
    addEdge(newGraph, 2, 4);
    addEdge(newGraph, 2, 0);
    addEdge(newGraph, 3, 5);
    addEdge(newGraph, 3, 1);
    addEdge(newGraph, 4, 2);
    addEdge(newGraph, 5, 3);

    printf("\nBFS traversal:\n");
    BFS(newGraph, 0);

    destroyGraph(newGraph);

    return 0;
}
