#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void initArray(Node** arr, int num) {
    for (int i = 0; i < num; i++) {
        arr[i] = (Node*)malloc(sizeof(Node));//对我们的数组里面存储好的结点进行内存的分配
        arr[i]->vertex = i + 1;
        arr[i]->next = NULL;
    }
}
void printArray(Node** arr, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\t%d\n",arr[i]->vertex);
    }
}
int main() {
    int num = 6;
    Node** arr = (Node**)malloc(num * sizeof(Node*)); // 分配内存空间

    initArray(arr, num);
    printArray(arr, num);
    // 在这里可以继续操作 arr 数组中的节点

    // 释放内存
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
