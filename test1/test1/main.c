#include <stdio.h>
#include "graph.h"

int main() {
    int numVertices, numEdges;//�������������ǵ�
    printf("�����붥�����ͱ�����");
    scanf_s("%d %d", &numVertices, &numEdges);

    Graph* graph = createGraph(numVertices);

    printf("������ÿ���ߵ���㡢�յ��Ȩ�أ�\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf_s("%d %d %d", &src, &dest, &weight);
        addEdge(graph, src, dest, weight);
    }

    primMST(graph);
    kruskalMST(graph);

    return 0;
}
