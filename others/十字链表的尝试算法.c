#include <stdio.h>
#include <stdlib.h>
#define MAXVX 20
typedef struct VertexNode {
    int vertex;  // 顶点值
    struct ArcNode* firstIn;   // 入边表头指针
    struct ArcNode* firstOut;  // 出边表头指针
} VertexNode;

typedef struct ArcNode {
    int tailVertex;  // 弧尾顶点
    int headVertex;  // 弧头顶点
    struct ArcNode* tailLink;  // 指向弧尾相同的下一条弧
    struct ArcNode* headLink;  // 指向弧头相同的下一条弧
} ArcNode;

typedef struct CrossLinkedList {
    VertexNode vertexArray[MAXVX];  // 顶点数组
    int vertexCount;  // 顶点数量
} CrossLinkedList;

void initCrossLinkedList(CrossLinkedList* graph, int vertexCount) {
    graph->vertexCount = vertexCount;
    for (int i = 0; i < vertexCount; i++) {
        graph->vertexArray[i].vertex = i;
        graph->vertexArray[i].firstIn = NULL;
        graph->vertexArray[i].firstOut = NULL;
    }
}

void addArc(CrossLinkedList* graph, int tailVertex, int headVertex) {
    ArcNode* arcNode = (ArcNode*)malloc(sizeof(ArcNode));
    arcNode->tailVertex = tailVertex;
    arcNode->headVertex = headVertex;
    arcNode->tailLink = NULL;
    arcNode->headLink = NULL;

    // 插入到出边表
    if (graph->vertexArray[tailVertex].firstOut == NULL) {
        graph->vertexArray[tailVertex].firstOut = arcNode;
    } else {
        ArcNode* currArc = graph->vertexArray[tailVertex].firstOut;
        while (currArc->tailLink != NULL) {
            currArc = currArc->tailLink;
        }
        currArc->tailLink = arcNode;
    }

    // 插入到入边表
    if (graph->vertexArray[headVertex].firstIn == NULL) {
        graph->vertexArray[headVertex].firstIn = arcNode;
    } else {
        ArcNode* currArc = graph->vertexArray[headVertex].firstIn;
        while (currArc->headLink != NULL) {
            currArc = currArc->headLink;
        }
        currArc->headLink = arcNode;
    }
}

void printCrossLinkedList(CrossLinkedList* graph) {
    for (int i = 0; i < graph->vertexCount; i++) {
        printf("顶点 %d：", graph->vertexArray[i].vertex);

        printf(" 出边：");
        ArcNode* outArc = graph->vertexArray[i].firstOut;
        while (outArc != NULL) {
            printf("(%d, %d) ", outArc->tailVertex, outArc->headVertex);
            outArc = outArc->tailLink;
        }

        printf(" 入边：");
        ArcNode* inArc = graph->vertexArray[i].firstIn;
        while (inArc != NULL) {
            printf("(%d, %d) ", inArc->tailVertex, inArc->headVertex);
            inArc = inArc->headLink;
        }

        printf("\n");
    }
}

int main() {
    CrossLinkedList graph;
    int vertexCount = 5;

    initCrossLinkedList(&graph, vertexCount);

    addArc(&graph, 0, 1);
    addArc(&graph, 0, 2);
    addArc(&graph, 1, 2);
    addArc(&graph, 1, 3);
    addArc(&graph, 2, 3);
    addArc(&graph, 3, 4);

    printCrossLinkedList(&graph);

    return 0;
}
