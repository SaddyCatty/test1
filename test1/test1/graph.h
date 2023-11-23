#ifndef GRAPH_H
#define GRAPH_H

// �ߵĽṹ��
typedef struct Edge {
    int src;   // ��ʼ����
    int dest;  // Ŀ�궥��
    int weight; // Ȩ��
} Edge;

// �ڽӱ��еĽڵ�
typedef struct ListNode {
    int dest; // Ŀ�궥��
    int weight; // Ȩ��
    struct ListNode* next; // ��һ���ڵ�
} ListNode;

// ͼ�Ľṹ�壬ʹ���ڽӱ��ʾ
typedef struct Graph {
    int numVertices; // ������
    int numEdges;    // ����
    ListNode** adjacencyList; // �ڽӱ�����
} Graph;

// ����һ���µ�ͼ
Graph* createGraph(int numVertices);

// ��ӱߵ�ͼ��
void addEdge(Graph* graph, int src, int dest, int weight);

// Prim�㷨����С������
void primMST(Graph* graph);

// Kruskal�㷨����С������
void kruskalMST(Graph* graph);

#endif // GRAPH_H
#pragma once
