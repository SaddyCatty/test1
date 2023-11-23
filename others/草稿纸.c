#include <stdio.h>
#include <stdlib.h>

typedef struct ElemType{
    int score;
}ElemType;
typedef struct Node{
    ElemType data;
    struct Node* left;
    struct Node* right;
}Node;
void insertAtTail(Node** head , int num , int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data.score = data;
    newNode->left = NULL;
    newNode->right = NULL;
    Node* temp = head[num];
        while(temp->right != NULL)
    {
        temp = temp->right;
    }
    temp -> right = newNode;
    newNode -> left = temp;
}
void printList(Node** head , int martix)
{
    for(int i = 0 ; i < martix ; i++)
    {
        int count = 1;
        Node* temp = head[i];
        while(temp != NULL)
        {
            printf("\n对于第%d个链表而言，存储的第%d个数是：%d\n",(i+1),count,temp->data.score);
            temp = temp->right;
            count++;
        }
        printf("\n");
    }
}
int main()
{
    int martix = 6;
    Node** head = (Node**)malloc(martix*sizeof(Node*));
    for(int i = 0 ; i < martix ; i++)
    {
        head[i] = (Node*)malloc(sizeof(Node));
        head[i]->left = NULL;
        head[i]->right = NULL;
        head[i]->data.score = i;
    }
    for(int i = 0 ; i < martix ; i++)
    {
        printf("%d\t",head[i]->data.score);
    }
    insertAtTail( head , 0 , 12);
    insertAtTail( head , 1 , 13);
    printList( head , 6);
    return 0;
}
