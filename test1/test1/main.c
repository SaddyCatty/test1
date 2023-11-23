#include <stdio.h>
#include "graph.h"

int main() {
    int numVertices, numEdges;//在这里输入我们的
    printf("请输入顶点数和边数：");
    scanf_s("%d %d", &numVertices, &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("请输入每条边的起点、终点和权重：\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf_s("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);
    kruskalMST(graph);

    return 0;
}
