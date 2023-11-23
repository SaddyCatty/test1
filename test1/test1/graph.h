#ifndef GRAPH_H
#define GRAPH_H

// 边的结构体
typedef struct Edge {
    int src;   // 起始顶点
    int dest;  // 目标顶点
    int weight; // 权重
} Edge;

// 邻接表中的节点
typedef struct ListNode {
    int dest; // 目标顶点
    int weight; // 权重
    struct ListNode* next; // 下一个节点
} ListNode;

// 图的结构体，使用邻接表表示
typedef struct Graph {
    int numVertices; // 顶点数
    int numEdges;    // 边数
    ListNode** adjacencyList; // 邻接表数组
} Graph;

// 创建一个新的图
Graph* createGraph(int numVertices);

// 添加边到图中
void addEdge(Graph* graph, int src, int dest, int weight);

// Prim算法求最小生成树
void primMST(Graph* graph);

// Kruskal算法求最小生成树
void kruskalMST(Graph* graph);

#endif // GRAPH_H
#pragma once
