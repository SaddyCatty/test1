#include "frequency_counter.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int compare(const void* a, const void* b) {
    return ((FrequencyPair*)b)->frequency - ((FrequencyPair*)a)->frequency;
}

FrequencyPair* sortCharactersByFrequency(const char* text) {
    if (text == NULL)
        return NULL;

    int count[256] = {0};  // ֻͳ�� ASCII ��СдӢ��
    for (int i = 0; text[i] != '\0' ; i++) {
        unsigned char c = (unsigned char)text[i];
        if (isprint(c)) {  // ֻ����ɴ�ӡ�ַ�
            count[c]++;
        }
    }

    FrequencyPair* pairs = malloc(256 * sizeof(FrequencyPair));  // �����С��Ϊ 256
    if (pairs == NULL)
        return NULL;

    int numPairs = 0;
    for (int i = 0; i < 256; i++) {
        if (count[i] > 0) {
            pairs[numPairs].character = (char)i;
            pairs[numPairs].frequency = count[i];
            numPairs++;
        }
    }

    qsort(pairs, numPairs, sizeof(FrequencyPair), compare);

    return pairs;
}
