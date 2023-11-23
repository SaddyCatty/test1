#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// ��ʼ������
void initializeLinkedList(Node** head) {
    *head = NULL;
}

// ������ͷ������ڵ�
void insertAtHead(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));//�����������õ�malloc���������Ƕ����ڴ�ķ�����Ҫ��һ��ָ����䣬Ϊָ��ָ��ĵ�ַ�����ڴ�
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;//�������ǵĸı��ַ��λ�õ�һ��ָ������Ҫ�����������ǵ�˫��ָ��
}

// ������β������ڵ�
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

// ��ָ��λ�ò���ڵ�
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

// ɾ��ͷ�ڵ�
void deleteAtHead(Node** head) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// ɾ��β�ڵ�
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

// ɾ��ָ��λ�õĽڵ�
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

// ��ȡ������
int getLength(const Node* head) {
    int length = 0;
    Node* currentNode = head;
    while (currentNode != NULL) {
        ++length;
        currentNode = currentNode->next;
    }
    return length;
}

// ��ӡ����Ԫ��
void printLinkedList(const Node* head) {
    Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}
