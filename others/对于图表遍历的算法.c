#include <stdio.h>
#include <stdlib.h>
typedef struct ANode{
    int adj;
    struct ANode* next;
}ANode;//定义结点数据结构

typedef struct ElemType{
    int num;
    char word;
}ElemType;

typedef struct VNode{
    ElemType data;//定义数据类型
    ANode* firststare;//定义指向ANode的指针
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
    ANode* newNode = (ANode*)malloc(sizeof(ANode));//记得内存的分配
    newNode->adj = 0 ;
    newNode->next = NULL;
    Map.vers[0].firststare ->next = newNode;
    printf("%d\n",(Map.vers[0].firststare->next)->adj);
    return 0;
}

