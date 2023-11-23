#include <stdlib.h>
#include "map.h"

void destroyGraph(Graph* graph) {
    // �ͷ��ڽӾ�����ڴ�
    for (int i = 0; i < graph->numVertices; i++) {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);

    // �ͷ��ڽӱ���ڴ�
    for (int i = 0; i < graph->numVertices; i++) {
        ListNode* curr = graph->adjList[i];
        while (curr != NULL) {
            ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(graph->adjList);

    // �ͷ�ͼ���ڴ�
    free(graph);
}

