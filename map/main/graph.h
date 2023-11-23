#ifndef GRAPH_H
#define GRAPH_H

// 定义列表节点
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// 定义队列节点
typedef struct QueueNode {
    int vertex;
    struct QueueNode* next;
} QueueNode;

// 定义图
typedef struct Graph {
    int numVertices;
    Node** adjLists;//相当于我们对应的每个单链表的头指针（二重指针）
    int* visited;//给我们进行的访问加一个指针
} Graph;

// 函数声明
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void DFS(Graph* graph, int vertex);
void BFS(Graph* graph, int startVertex);
void destroyGraph(Graph* graph);
void printAdjMatrix(Graph* graph);
#endif
