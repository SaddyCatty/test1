#include <stdlib.h>
#include "map.h"

void destroyGraph(Graph* graph) {
    // 释放邻接矩阵的内存
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);

    // 释放邻接表的内存
    for (int i = 0; i < graph->numVertices; i++) {
        ListNode* curr = graph->adjList[i];
        while (curr != NULL) {
            ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->adjList);

    // 释放图的内存
    free(graph);
}

