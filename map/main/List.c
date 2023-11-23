#include <stdlib.h>
#include <stdio.h>
#include "map.h"

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // �����ڽӾ���
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        memset(graph->adjMatrix[i], 0, numVertices * sizeof(int)); // ��ʼ��Ϊ0
    }

    // �����ڽӱ�
    graph->adjList = (ListNode**)malloc(numVertices * sizeof(ListNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL; // ��ʼ��Ϊ������
    }

    return graph;
}

void buildAdjacencyList(Graph* graph, int a[][Elem], int elem) {
    for (int i = 0; i < elem; i++) {
        for (int j = 0; j < elem; j++) {
            if (a[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}

void printGraph(Graph* graph) {
    printf("�ڽӱ�\n");
    for (int i = 0; i < graph->numVertices; i++) {
        ListNode* curr = graph->adjList[i];
        printf("���� %d ���ڽ��б�: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

