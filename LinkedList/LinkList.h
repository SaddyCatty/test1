#ifndef LINKLIST_H
#define LINKLST_H
typedef struct ElemType{
    int score;
    char name[20];
}ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;
void initLink(Node** head);
void insertAtTail(Node** head);
void printList (Node* head);
void deleteNode(Node** head , int position);
void destroyLink(Node** head);
void insertInLink(Node** head , int pos);
#endif // LINKLIST_H
