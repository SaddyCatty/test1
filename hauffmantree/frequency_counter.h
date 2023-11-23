#ifndef FREQUENCY_COUNTER_H
#define FREQUENCY_COUNTER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char character;
    int frequency;
} FrequencyPair;//定义一个结构体来存储字符与对应相应的出现次数
int compare(const void* a, const void* b) ;
FrequencyPair* sortCharactersByFrequency(const char* text);
#endif
