#include "map.h"
#include <stdio.h>
#include <stdlib.h>

void getElem(int elem)
{
    Elem = elem;
}

void assignAdjacencyMatrix(int a[][Elem], int elem) {
    int counter;
    char decide;
    for (int i = 0; i < elem; i++) {
        counter = 1;
        do {
            printf("%d号元素是否与%d之间连通？(y/n)\n", (i + 1), counter);
            getchar();
            decide = getchar();
            if (decide == 'y' || decide == 'Y') {
                a[i][counter - 1] = 1;
                printf("stored!\n");
            }
            counter++;
        } while (counter <= elem);
    }
}

void printMatrix(int a[][Elem], int elem) {
    for (int i = 0; i < elem; i++) {
        for (int j = 0; j < elem; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void buildchart(int a[][Elem], int elem)
{
    // 补全邻接表的建立逻辑
}

void insertNodeAtTail(ListNode** head, int ElemNumber)
{
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    newNode->vertex= ElemNumber;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void freeMapnode()
{
    // 补全释放链表节点的逻辑
}
