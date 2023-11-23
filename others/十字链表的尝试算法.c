#include <stdio.h>
#include <stdlib.h>
#define MAXVX 20
typedef struct VertexNode {
    int vertex;  // ����ֵ
    struct ArcNode* firstIn;   // ��߱�ͷָ��
    struct ArcNode* firstOut;  // ���߱�ͷָ��
} VertexNode;

typedef struct ArcNode {
    int tailVertex;  // ��β����
    int headVertex;  // ��ͷ����
    struct ArcNode* tailLink;  // ָ��β��ͬ����һ����
    struct ArcNode* headLink;  // ָ��ͷ��ͬ����һ����
} ArcNode;

typedef struct CrossLinkedList {
    VertexNode vertexArray[MAXVX];  // ��������
    int vertexCount;  // ��������
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

    // ���뵽���߱�
    if (graph->vertexArray[tailVertex].firstOut == NULL) {
        graph->vertexArray[tailVertex].firstOut = arcNode;
    } else {
        ArcNode* currArc = graph->vertexArray[tailVertex].firstOut;
        while (currArc->tailLink != NULL) {
            currArc = currArc->tailLink;
        }
        currArc->tailLink = arcNode;
    }

    // ���뵽��߱�
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
        printf("���� %d��", graph->vertexArray[i].vertex);

        printf(" ���ߣ�");
        ArcNode* outArc = graph->vertexArray[i].firstOut;
        while (outArc != NULL) {
            printf("(%d, %d) ", outArc->tailVertex, outArc->headVertex);
            outArc = outArc->tailLink;
        }

        printf(" ��ߣ�");
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
