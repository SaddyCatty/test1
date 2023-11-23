#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
/*typedef struct ElemType{
    int score;
    char name[20];
}ElemType;
typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;
void initLink(Node** head) {
    *head = malloc(sizeof(Node));
    (*head)->next = NULL;
}
void insertAtTail(Node** head)
{
    int score;
    char name[20];
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Please Enter Student Name:\n");
    scanf("%s",&(newNode->data.name));
    printf("Please Enter Student Score:\n");
    scanf("%d",&(newNode->data.score));
    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else{
        Node* temp = *head;//����һ����ʱ�ķ���ָ��temp
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = NULL;
    }
}
void printList (Node* head)
{
    Node* temp = head->next;
    while(temp!= NULL)
    {

        printf("%s\t%d\n",temp->data.name,temp->data.score);
        temp = temp->next;
    }
}
void deleteNode(Node** head , int position)
{
    Node* temp = *head;
    for(int i=0;i<(position-1);i++)
    {
        temp = temp->next;
    }
    Node* freename = temp;
    freename = freename->next;
    temp->next = temp->next->next;
    free(freename);
}
void destroyLink(Node** head)
{
    Node* p = *head;
    Node* q = *head;
    q = (*head)->next;
    while(p)
    {
        p=q;
        q = q->next;
        free(p);
    }
    (*head)->next = NULL;
}
void insertInLink(Node** head , int pos)
{
    int score;
    char name[20];
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Please Enter Student Name:\n");
    scanf("%s",&(newNode->data.name));
    printf("Please Enter Student Score:\n");
    scanf("%d",&(newNode->data.score));
    if(*head == NULL)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else{
        Node* temp = *head;//����һ����ʱ�ķ���ָ��temp
        for(int i=0;i<pos;i++)
        {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = newNode;
        newNode->next = temp1;
    }
}*/
int main()
{
    Node* head;//ע������������Ҫ����һ��ָ��Node��ָ��head��ͷָ��
    initLink(&head);//�����ǵ�ͷָ������ڴ棬����ָ���
    insertAtTail(&head);
    insertAtTail(&head);
    insertAtTail(&head);
    printList(head);
    deleteNode(&head,2);
    printf("After Deleted the second data:\n");
    insertInLink(&head,0);
    printList(head);
    destroyLink(&head);
    return 0;
}
