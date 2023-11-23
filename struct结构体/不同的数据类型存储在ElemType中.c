#include <stdio.h>
#include <stdlib.h>
typedef struct ElemType{
    int data;
    char word;
    float doubles;
}ElemType;
int main()
{
    ElemType* datas = (ElemType*)malloc(sizeof(ElemType));
    datas->data = 10;
    datas->word = 'A';
    datas->doubles = 9.9;
    printf("data:\t%d\n",datas->data);
    printf("word:\t%c\n",datas->word);
    printf("doubles:\t%f\n",datas->doubles);
    ElemType a[10];
    printf("%d",a[0].data);
    return 0;
}
