#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// ����ڵ�ṹ��
typedef struct Node {
    int data;           // �ڵ�洢������
    struct Node* next;  // ָ����һ���ڵ��ָ��
} Node;

// ��ʼ������
void initializeLinkedList(Node** head);

// ������ͷ������ڵ�
void insertAtHead(Node** head, int data);

// ������β������ڵ�
void insertAtTail(Node** head, int data);

// ��ָ��λ�ò���ڵ�
void insertAtPosition(Node** head, int data, int position);

// ɾ��ͷ�ڵ�
void deleteAtHead(Node** head);

// ɾ��β�ڵ�
void deleteAtTail(Node** head);

// ɾ��ָ��λ�õĽڵ�
void deleteAtPosition(Node** head, int position);

// ��ȡ������
int getLength(const Node* head);

// ��ӡ����Ԫ��
void printLinkedList(const Node* head);

#endif
