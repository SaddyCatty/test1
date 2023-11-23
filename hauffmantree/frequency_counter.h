#ifndef FREQUENCY_COUNTER_H
#define FREQUENCY_COUNTER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char character;
    int frequency;
} FrequencyPair;//����һ���ṹ�����洢�ַ����Ӧ��Ӧ�ĳ��ִ���
int compare(const void* a, const void* b) ;
FrequencyPair* sortCharactersByFrequency(const char* text);
#endif
