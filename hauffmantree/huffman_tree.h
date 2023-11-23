#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "frequency_counter.h"

typedef struct HuffmanNode {
    char character;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
} HuffmanNode;

void generateHuffmanCodes(HuffmanNode* root, char* prefix, int depth);
char* encodeText(const char* text, HuffmanNode* root);
void encodeCharacter(HuffmanNode* node, char character, char* code, int depth, char* encodedText);
char* decodeText(const char* encodedText, HuffmanNode* root);
void decodeCharacter(HuffmanNode* node, const char* encodedText, int* index, char* decodedText);
int compareText(const char* text1, const char* text2);

HuffmanNode* buildHuffmanTree(FrequencyPair* pairs, int numPairs);
void freeHuffmanTree(HuffmanNode* root);

#endif  // HUFFMAN_TREE_H
