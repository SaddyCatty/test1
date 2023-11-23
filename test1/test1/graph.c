#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// ����һ���µ�ͼ
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    // �����ڽӱ����飬����ʼ��ΪNULL
    graph->adjacencyList = (ListNode**)malloc(numVertices * sizeof(ListNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// ��ӱߵ�ͼ��
void addEdge(Graph* graph, int src, int dest, int weight) {
    // �����µ��ڽӱ�ڵ�
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;

    // ���ڵ���뵽Դ������ڽӱ���
    if (graph->adjacencyList[src] == NULL) {
        graph->adjacencyList[src] = newNode;
    }
    else {
        ListNode* temp = graph->adjacencyList[src];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // ����������ͼ�����轫����ӵ�Ŀ�궥����ڽӱ���
    newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = src;
    newNode->weight = weight;
    newNode->next = NULL;

    if (graph->adjacencyList[dest] == NULL) {
        graph->adjacencyList[dest] = newNode;
    }
    else {
        ListNode* temp = graph->adjacencyList[dest];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    graph->numEdges++;
}

// ����һ���µĽڵ�
ListNode* createNode(int dest, int weight) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Prim�㷨����С������
void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(numVertices * sizeof(int)); // �洢��С��������ÿ������ĸ��ڵ�
    int* key = (int*)malloc(numVertices * sizeof(int)); // �洢ÿ�����㵽��С����������СȨ��
    int* selected = (int*)malloc(numVertices * sizeof(int)); // ��¼�����Ƿ�ѡ����С��������

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX; // �����ж����key��ʼ��Ϊ�����
        selected[i] = 0; // ��ʼ�����ж���Ϊδѡ��״̬
    }

    key[0] = 0; // ��һ��������Ϊ��ʼ����

    for (int count = 0; count < numVertices - 1; count++) {
        int minKey = INT_MAX;
        int minIndex;

        // ��δѡ��Ķ������ҵ�keyֵ��С�Ķ���
        for (int v = 0; v < numVertices; v++) {
            if (selected[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        selected[minIndex] = 1; // ���ö�����Ϊ��ѡ��

        // ��������С���������ڵĶ����keyֵ��parent
        ListNode* temp = graph->adjacencyList[minIndex];
        while (temp != NULL) {
            int adjVertex = temp->dest;
            int weight = temp->weight;
            if (selected[adjVertex] == 0 && weight < key[adjVertex]) {
                parent[adjVertex] = minIndex;
                key[adjVertex] = weight;
            }
            temp = temp->next;
        }
    }

    // �����С�������Ľ��
    printf("Prim�㷨��õ���С��������\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d\n", parent[i], i);
    }

    // �ͷŶ�̬������ڴ�
    free(parent);
    free(key);
    free(selected);
}

// ���鼯�Ľṹ��
typedef struct UnionFind {
    int* parent;
    int* rank;
} UnionFind;

// �������鼯
UnionFind* createUnionFind(int numVertices) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(numVertices * sizeof(int));
    uf->rank = (int*)malloc(numVertices * sizeof(int));

    // ��ʼ�����鼯
    for (int i = 0; i < numVertices; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }

    return uf;
}

// ���Ҷ��������ļ��ϣ���·��ѹ���Ż���
int find(UnionFind* uf, int vertex) {
    if (uf->parent[vertex] != vertex) {
        uf->parent[vertex] = find(uf, uf->parent[vertex]); // ·��ѹ��
    }
    return uf->parent[vertex];
}

// �ϲ��������ϣ����Ⱥϲ��Ż���
void unionSets(UnionFind* uf, int x, int y) {
    int rootX = find(uf, x);
    int rootY = find(uf, y);

    if (uf->rank[rootX] < uf->rank[rootY]) {
        uf->parent[rootX] = rootY;
    }
    else if (uf->rank[rootX] > uf->rank[rootY]) {
        uf->parent[rootY] = rootX;
    }
    else {
        uf->parent[rootY] = rootX;
        uf->rank[rootX]++;
    }
}

// ��Ȩ����������ߵıȽϺ���
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal�㷨����С������
void kruskalMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int numEdges = graph->numEdges;
    Edge* edges = (Edge*)malloc(numEdges * sizeof(Edge));

    // ��ͼ�еıߴ洢��������
    int index = 0;
    for (int i = 0; i < numVertices; i++) {
        ListNode* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            if (i < temp->dest) { // ����������ͼ��ֻ�账��һ��ÿ����
                edges[index].src = i;
                edges[index].dest = temp->dest;
                edges[index].weight = temp->weight;
                index++;
            }
            temp = temp->next;
        }
    }

    // �Ա߰�Ȩ����������
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // �������鼯
    UnionFind* uf = createUnionFind(numVertices);

    // ��С�������ı߼���
    Edge* result = (Edge*)malloc((numVertices - 1) * sizeof(Edge));
    int count = 0;

    for (int i = 0; i < numEdges; i++) {
        Edge currentEdge = edges[i];

        int srcRoot = find(uf, currentEdge.src);
        int destRoot = find(uf, currentEdge.dest);

        // �����ǰ�߲����γɻ�·�����������С�������ı߼���
        if (srcRoot != destRoot) {
            result[count++] = currentEdge;
            unionSets(uf, srcRoot, destRoot);
        }
    }

    // �����С�������Ľ��
    printf("Kruskal�㷨��õ���С��������\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d\n", result[i].src, result[i].dest);
    }

    // �ͷŶ�̬������ڴ�
    free(edges);
    free(result);
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

