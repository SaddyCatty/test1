#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

void initArray(Node** arr, int num) {
    for (int i = 0; i < num; i++) {
        arr[i] = (Node*)malloc(sizeof(Node));//�����ǵ���������洢�õĽ������ڴ�ķ���
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
    Node** arr = (Node**)malloc(num * sizeof(Node*)); // �����ڴ�ռ�

    initArray(arr, num);
    printArray(arr, num);
    // ��������Լ������� arr �����еĽڵ�

    // �ͷ��ڴ�
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
