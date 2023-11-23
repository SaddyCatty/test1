#ifndef MAP_H
#define MAP_H

typedef struct ListNode {
    int vertex;
    struct ListNode* next;
} ListNode;

typedef struct Graph {
    int numVertices;
    int** adjMatrix; // �ڽӾ���
    ListNode** adjList; // �ڽӱ�
} Graph;

extern int Elem;

void assignAdjacencyMatrix(int a[][Elem], int elem);
void printMatrix(int a[][Elem], int elem);

Graph* createGraph(int numVertices);
void buildAdjacencyList(Graph* graph, int a[][Elem], int elem);
void printGraph(Graph* graph);
void destroyGraph(Graph* graph);

#endif // MAP_H
