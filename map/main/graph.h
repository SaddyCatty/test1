#ifndef GRAPH_H
#define GRAPH_H

// �����б�ڵ�
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// ������нڵ�
typedef struct QueueNode {
    int vertex;
    struct QueueNode* next;
} QueueNode;

// ����ͼ
typedef struct Graph {
    int numVertices;
    Node** adjLists;//�൱�����Ƕ�Ӧ��ÿ���������ͷָ�루����ָ�룩
    int* visited;//�����ǽ��еķ��ʼ�һ��ָ��
} Graph;

// ��������
Graph* createGraph(int vertices);
void addEdge(Graph* graph, int src, int dest);
void printGraph(Graph* graph);
void DFS(Graph* graph, int vertex);
void BFS(Graph* graph, int startVertex);
void destroyGraph(Graph* graph);
void printAdjMatrix(Graph* graph);
#endif
