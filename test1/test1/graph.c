#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

// 创建一个新的图
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->numEdges = 0;

    // 创建邻接表数组，并初始化为NULL
    graph->adjacencyList = (ListNode**)malloc(numVertices * sizeof(ListNode*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
    }

    return graph;
}

// 添加边到图中
void addEdge(Graph* graph, int src, int dest, int weight) {
    // 创建新的邻接表节点
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;

    // 将节点插入到源顶点的邻接表中
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

    // 由于是无向图，还需将边添加到目标顶点的邻接表中
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

// 创建一个新的节点
ListNode* createNode(int dest, int weight) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

// Prim算法求最小生成树
void primMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int* parent = (int*)malloc(numVertices * sizeof(int)); // 存储最小生成树中每个顶点的父节点
    int* key = (int*)malloc(numVertices * sizeof(int)); // 存储每个顶点到最小生成树的最小权重
    int* selected = (int*)malloc(numVertices * sizeof(int)); // 记录顶点是否被选择到最小生成树中

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX; // 将所有顶点的key初始化为无穷大
        selected[i] = 0; // 初始化所有顶点为未选择状态
    }

    key[0] = 0; // 第一个顶点作为起始顶点

    for (int count = 0; count < numVertices - 1; count++) {
        int minKey = INT_MAX;
        int minIndex;

        // 在未选择的顶点中找到key值最小的顶点
        for (int v = 0; v < numVertices; v++) {
            if (selected[v] == 0 && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        selected[minIndex] = 1; // 将该顶点标记为已选择

        // 更新与最小生成树相邻的顶点的key值和parent
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

    // 输出最小生成树的结果
    printf("Prim算法求得的最小生成树：\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d\n", parent[i], i);
    }

    // 释放动态分配的内存
    free(parent);
    free(key);
    free(selected);
}

// 并查集的结构体
typedef struct UnionFind {
    int* parent;
    int* rank;
} UnionFind;

// 创建并查集
UnionFind* createUnionFind(int numVertices) {
    UnionFind* uf = (UnionFind*)malloc(sizeof(UnionFind));
    uf->parent = (int*)malloc(numVertices * sizeof(int));
    uf->rank = (int*)malloc(numVertices * sizeof(int));

    // 初始化并查集
    for (int i = 0; i < numVertices; i++) {
        uf->parent[i] = i;
        uf->rank[i] = 0;
    }

    return uf;
}

// 查找顶点所属的集合（带路径压缩优化）
int find(UnionFind* uf, int vertex) {
    if (uf->parent[vertex] != vertex) {
        uf->parent[vertex] = find(uf, uf->parent[vertex]); // 路径压缩
    }
    return uf->parent[vertex];
}

// 合并两个集合（按秩合并优化）
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

// 按权重升序排序边的比较函数
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal算法求最小生成树
void kruskalMST(Graph* graph) {
    int numVertices = graph->numVertices;
    int numEdges = graph->numEdges;
    Edge* edges = (Edge*)malloc(numEdges * sizeof(Edge));

    // 将图中的边存储到数组中
    int index = 0;
    for (int i = 0; i < numVertices; i++) {
        ListNode* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            if (i < temp->dest) { // 由于是无向图，只需处理一次每条边
                edges[index].src = i;
                edges[index].dest = temp->dest;
                edges[index].weight = temp->weight;
                index++;
            }
            temp = temp->next;
        }
    }

    // 对边按权重升序排序
    qsort(edges, numEdges, sizeof(Edge), compareEdges);

    // 创建并查集
    UnionFind* uf = createUnionFind(numVertices);

    // 最小生成树的边集合
    Edge* result = (Edge*)malloc((numVertices - 1) * sizeof(Edge));
    int count = 0;

    for (int i = 0; i < numEdges; i++) {
        Edge currentEdge = edges[i];

        int srcRoot = find(uf, currentEdge.src);
        int destRoot = find(uf, currentEdge.dest);

        // 如果当前边不会形成环路，则将其加入最小生成树的边集合
        if (srcRoot != destRoot) {
            result[count++] = currentEdge;
            unionSets(uf, srcRoot, destRoot);
        }
    }

    // 输出最小生成树的结果
    printf("Kruskal算法求得的最小生成树：\n");
    for (int i = 0; i < count; i++) {
        printf("%d - %d\n", result[i].src, result[i].dest);
    }

    // 释放动态分配的内存
    free(edges);
    free(result);
    free(uf->parent);
    free(uf->rank);
    free(uf);
}

