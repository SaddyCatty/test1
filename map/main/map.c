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
            printf("%d��Ԫ���Ƿ���%d֮����ͨ��(y/n)\n", (i + 1), counter);
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
    // ��ȫ�ڽӱ�Ľ����߼�
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
    // ��ȫ�ͷ�����ڵ���߼�
}
