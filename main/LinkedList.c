#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 初始化链表
void initializeLinkedList(Node** head) {
    *head = NULL;
}

// 在链表头部插入节点
void insertAtHead(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//对于我们引用的malloc函数，我们对于内存的分配需要对一个指针分配，为指针指向的地址分配内存
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;//对于我们的改变地址与位置的一个指针我们要对于引用我们的双重指针
}

// 在链表尾部插入节点
void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* currentNode = *head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

// 在指定位置插入节点
void insertAtPosition(Node** head, int data, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        insertAtHead(&head, data);
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    Node* currentNode = *head;
    for (int i = 0; i < position - 1; ++i) {
        if (currentNode == NULL) {
            printf("Invalid position.\n");
            free(newNode);
            return;
        }
        currentNode = currentNode->next;
    }

    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

// 删除头节点
void deleteAtHead(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// 删除尾节点
void deleteAtTail(Node** head) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    Node* currentNode = *head;
    while (currentNode->next->next != NULL) {
        /*while(currentNode->next != NULL)
            {
                        currentNode = currentNode ->next;
            }
                         free(currentNode);

                    */



        currentNode = currentNode->next;
    }

    free(currentNode->next);
    currentNode->next = NULL;
}

// 删除指定位置的节点
void deleteAtPosition(Node** head, int position) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 0) {
        deleteAtHead(head);
        return;
    }

    Node* currentNode = *head;
    for (int i = 0; i < position - 1; ++i) {
        if (currentNode == NULL || currentNode->next == NULL) {
            printf("Invalid position.\n");
            return;
        }
        currentNode = currentNode->next;
    }

    Node* temp = currentNode->next;
    currentNode->next = currentNode->next->next;
    free(temp);
}

// 获取链表长度
int getLength(const Node* head) {
    int length = 0;
    Node* currentNode = head;
    while (currentNode != NULL) {
        ++length;
        currentNode = currentNode->next;
    }
    return length;
}

// 打印链表元素
void printLinkedList(const Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}
