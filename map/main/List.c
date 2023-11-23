#include <stdlib.h>
#include <stdio.h>
#include "map.h"

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;

    // 创建邻接矩阵
    graph->adjMatrix = (int**)malloc(numVertices * sizeof(int*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(numVertices * sizeof(int));
        memset(graph->adjMatrix[i], 0, numVertices * sizeof(int)); // 初始化为0
    }

    // 创建邻接表
    graph->adjList = (ListNode**)malloc(numVertices * sizeof(ListNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL; // 初始化为空链表
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
    printf("邻接表：\n");
    for (int i = 0; i < graph->numVertices; i++) {
        ListNode* curr = graph->adjList[i];
        printf("顶点 %d 的邻接列表: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

