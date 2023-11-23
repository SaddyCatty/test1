#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// 链表节点结构体
typedef struct Node {
    int data;           // 节点存储的数据
    struct Node* next;  // 指向下一个节点的指针
} Node;

// 初始化链表
void initializeLinkedList(Node** head);

// 在链表头部插入节点
void insertAtHead(Node** head, int data);

// 在链表尾部插入节点
void insertAtTail(Node** head, int data);

// 在指定位置插入节点
void insertAtPosition(Node** head, int data, int position);

// 删除头节点
void deleteAtHead(Node** head);

// 删除尾节点
void deleteAtTail(Node** head);

// 删除指定位置的节点
void deleteAtPosition(Node** head, int position);

// 获取链表长度
int getLength(const Node* head);

// 打印链表元素
void printLinkedList(const Node* head);

#endif
