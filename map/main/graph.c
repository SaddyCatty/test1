#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// 创建节点
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// 创建队列节点
QueueNode* createQueueNode(int v) {
    QueueNode* newQueueNode = malloc(sizeof(QueueNode));
    newQueueNode->vertex = v;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// 入队操作
void enqueue(QueueNode** front, QueueNode** rear, int v) {
    QueueNode* newNode = createQueueNode(v);
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

// 出队操作
int dequeue(QueueNode** front, QueueNode** rear) {
    if (*front == NULL)
        return -1;

    QueueNode* temp = *front;
    int vertex = temp->vertex;

    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;

    free(temp);

    return vertex;
}

// 创建图
Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// 添加边
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // 只在一个方向上添加边，避免重复
}

// 打印图的邻接表
void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nAdjacency List Vertex %d\nHead Node", v);
        while (temp) {
            printf("-> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// 深度优先遍历
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

// 广度优先遍历
void BFS(Graph* graph, int startVertex) {
    QueueNode *front = NULL, *rear = NULL;
    enqueue(&front, &rear, startVertex);
    graph->visited[startVertex] = 1;

    while (front != NULL) {
        int currentVertex = dequeue(&front, &rear);
        printf("Visited %d \n", currentVertex);

        Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0) {
                enqueue(&front, &rear, adjVertex);
                graph->visited[adjVertex] = 1; // 将相邻节点标记为已访问
            }
            temp = temp->next;
        }
    }
}

// 销毁图
void destroyGraph(Graph* graph) {
    // 释放每个顶点的邻接链表节点
    for (int v = 0; v < graph->numVertices; v++) {
        Node* adjList = graph->adjLists[v];
        while (adjList) {
            Node* temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }

    // 释放邻接链表数组
    free(graph->adjLists);

    // 释放顶点访问数组
    free(graph->visited);

    // 释放图结构体
    free(graph);
}
// 打印图的邻接矩阵
void printAdjMatrix(Graph* graph) {
    int vertices = graph->numVertices;
    int** adjMatrix = malloc(vertices * sizeof(int*));

    for (int i = 0; i < vertices; i++) {
        adjMatrix[i] = calloc(vertices, sizeof(int));
        Node* temp = graph->adjLists[i];

        while (temp) {
            adjMatrix[i][temp->vertex] = 1;
            temp = temp->next;
        }
    }

    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    // 释放邻接矩阵内存
    for (int i = 0; i < vertices; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);
}
