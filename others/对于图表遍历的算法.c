#include <stdio.h>
#include <stdlib.h>
typedef struct ANode{
    int adj;
    struct ANode* next;
}ANode;//���������ݽṹ

typedef struct ElemType{
    int num;
    char word;
}ElemType;

typedef struct VNode{
    ElemType data;//������������
    ANode* firststare;//����ָ��ANode��ָ��
}VNode;
#define MAXVN 20
typedef struct{
    VNode vers[MAXVN];
    int vexnum;
    int arcnum;
}ALGraph;
int main()
{
    ALGraph Map;
    Map.vexnum = 0;
    Map.arcnum = 0;
    Map.vers[0].data.num = 1;
    Map.vers[0].data.word = 'A';
    Map.vers[0].firststare->adj = 1;
    printf("%d\n",Map.vers[0].data.num);
    ANode* newNode = (ANode*)malloc(sizeof(ANode));//�ǵ��ڴ�ķ���
    newNode->adj = 0 ;
    newNode->next = NULL;
    Map.vers[0].firststare ->next = newNode;
    printf("%d\n",(Map.vers[0].firststare->next)->adj);
    return 0;
}

