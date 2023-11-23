#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "frequency_counter.h"
#include "huffman_tree.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    FILE* file = fopen(filename, "rt");
    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* text = (char*)malloc(file_size + 1);
    fread(text, 1, file_size, file);
    text[file_size] = '\0';

    fclose(file);

    FrequencyPair* sorted = sortCharactersByFrequency(text);
    if (sorted == NULL) {
        printf("Failed to sort characters by frequency.\n");
        return 1;
    }

    printf("Characters sorted by frequency:\n");
    unsigned int lastpos = 0;
    for (int i = 0; sorted[i].frequency > 0 && sorted[i].frequency <= file_size; i++) {
        printf("%c\t%d\n", sorted[i].character, sorted[i].frequency);
        lastpos++;
    }

    HuffmanNode* root = buildHuffmanTree(sorted, lastpos);
    if (root == NULL) {
        printf("Failed to build Huffman tree.\n");
        free(sorted);
        free(text);
        return 1;
    }

    // ������������������Ӧ�Ĺ���������
    char prefix[100] = "";
    generateHuffmanCodes(root, prefix, 0);

    // ���ı����б���
    char* encodedText = encodeText(text, root);
    printf("\nEncoded Text: %s\n", encodedText);

    // �Ա����������
    char* decodedText = decodeText(encodedText, root);
    printf("Decoded Text: %s\n", decodedText);

    // �ж��������ı��Ƿ��ԭʼ�ı�һ��
    int isEqual = compareText(text, decodedText);
    if (isEqual) {
        printf("Decoded text matches the original text.\n");
    } else {
        printf("Decoded text does not match the original text.\n");
    }

    // �ͷ��ڴ�
    freeHuffmanTree(root);
    free(sorted);
    free(text);
    free(encodedText);
    free(decodedText);

    return 0;
}
