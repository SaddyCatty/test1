#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType {
    int num;
    char name[20];
} ElemType;

typedef struct Node {
    ElemType data;
    struct Node* left;
    struct Node* right;
} Node;

void initQueue(Node** front, Node** rear) {
    *front = NULL;
    *rear = NULL;
}

void enqueue(Node** front, Node** rear, ElemType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (*rear == NULL) {
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->right = newNode;
        newNode->left = *rear;
        *rear = newNode;
    }
}
ElemType dequeue(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        ElemType emptyElem = {-1, ""};  // 定义一个空元素作为错误提示
        return emptyElem;
    }

    Node* temp = *front;
    ElemType dequeuedElem = temp->data;

    *front = (*front)->right;
    if (*front == NULL) {
        *rear = NULL;
    } else {
        (*front)->left = NULL;
    }

    free(temp);
    return dequeuedElem;
}

int main() {
    Node* front;
    Node* rear;
    ElemType newElem = {1, "Kevin"};

    initQueue(&front, &rear);
    enqueue(&front, &rear, newElem);

    // 在这里可以继续操作队列

    // 释放内存
    while (front != NULL) {
        Node* temp = front;
        front = front->right;
        free(temp);
    }

    return 0;
}
