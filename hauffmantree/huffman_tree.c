#include "huffman_tree.h"
#include <stdlib.h>
#include <string.h>

typedef struct MinHeapNode {
    HuffmanNode* node;
    struct MinHeapNode* next;
} MinHeapNode;

typedef struct MinHeap {
    MinHeapNode* head;
    int size;
} MinHeap;

MinHeap* createMinHeap() {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->head = NULL;
    heap->size = 0;
    return heap;
}

void insertMinHeap(MinHeap* heap, HuffmanNode* node) {
    MinHeapNode* newNode = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    newNode->node = node;
    newNode->next = NULL;

    if (heap->head == NULL || node->frequency < heap->head->node->frequency) {
        newNode->next = heap->head;
        heap->head = newNode;
    } else {
        MinHeapNode* current = heap->head;
        while (current->next != NULL && current->next->node->frequency < node->frequency) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    heap->size++;
}


HuffmanNode* deleteMinHeap(MinHeap* heap) {
    if (heap->head == NULL) {
        return NULL;
    }

    MinHeapNode* temp = heap->head;
    heap->head = heap->head->next;
    HuffmanNode* node = temp->node;
    free(temp);

    heap->size--;

    return node;
}

HuffmanNode* createHuffmanNode(char character, int frequency) {
    HuffmanNode* newNode = (HuffmanNode*)malloc(sizeof(HuffmanNode));
    if (newNode != NULL) {
        newNode->character = character;
        newNode->frequency = frequency;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

void generateHuffmanCodes(HuffmanNode* root, char* prefix, int depth) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        prefix[depth] = '\0';
        printf("%c\t%s\n", root->character, prefix);
        return;
    }

    prefix[depth] = '0'; // 向左子树走
    generateHuffmanCodes(root->left, prefix, depth + 1);

    prefix[depth] = '1'; // 向右子树走
    generateHuffmanCodes(root->right, prefix, depth + 1);
}


char* encodeText(const char* text, HuffmanNode* root) {
    if (text == NULL || root == NULL) {
        return NULL;
    }

    int length = strlen(text);
    char* encodedText = (char*)malloc((length * 100 + 1) * sizeof(char));
    encodedText[0] = '\0';

    for (int i = 0; i < length; i++) {
        char character = text[i];
        char code[100] = "";
        encodeCharacter(root, character, code, 0, encodedText);
    }

    return encodedText;
}

void encodeCharacter(HuffmanNode* node, char character, char* code, int depth, char* encodedText) {
    if (node == NULL) {
        return;
    }

    if (node->left == NULL && node->right == NULL && node->character == character) {
        code[depth] = '\0';  // 更新字符串结束符的位置
        strcat(encodedText, code);
        return;
    }

    code[depth] = '0';
    encodeCharacter(node->left, character, code, depth + 1, encodedText);

    code[depth] = '1';
    encodeCharacter(node->right, character, code, depth + 1, encodedText);

    // 添加下面两行代码，在回溯时重置当前位
    code[depth] = '\0';
    return;
}


char* decodeText(const char* encodedText, HuffmanNode* root) {
    if (encodedText == NULL || root == NULL) {
        return NULL;
    }

    int length = strlen(encodedText);
    char* decodedText = (char*)malloc((length + 1) * sizeof(char));
    memset(decodedText, 0, length + 1); // 初始化为全零

    int index = 0;
    int decodedIndex = 0; // 添加一个新的变量来跟踪已解码的字符数
    HuffmanNode* current = root;

    while (index < length) {
        while (current->left != NULL && current->right != NULL) {
            if (encodedText[index] == '0') {
                current = current->left;
            } else if (encodedText[index] == '1') {
                current = current->right;
            }
            index++;
        }
        decodedText[decodedIndex++] = current->character; // 在此处更新解码文本和索引
        current = root;
    }

    decodedText[decodedIndex] = '\0'; // 在字符串末尾添加结束符
    return decodedText;
}




void decodeCharacter(HuffmanNode* node, const char* encodedText, int* index, char* decodedText) {
    if (node == NULL || encodedText[*index] == '\0') {
        return;
    }

    if (node->left == NULL && node->right == NULL) {
        decodedText[*index] = node->character;
        (*index)++;
        return;
    }

    if (encodedText[*index] == '0') {
        (*index)++;
        decodeCharacter(node->left, encodedText, index, decodedText);
    } else if (encodedText[*index] == '1') {
        (*index)++;
        decodeCharacter(node->right, encodedText, index, decodedText);
    }
}

int compareText(const char* text1, const char* text2) {
    if (text1 == NULL || text2 == NULL) {
        return 0;
    }

    return strcmp(text1, text2) == 0;
}

HuffmanNode* buildHuffmanTree(FrequencyPair* pairs, int numPairs) {
    if (numPairs == 0) {
        return NULL;
    }

    MinHeap* heap = createMinHeap();
    for (int i = 0; i < numPairs; i++) {
        HuffmanNode* node = createHuffmanNode(pairs[i].character, pairs[i].frequency);
        if (node != NULL) {
            insertMinHeap(heap, node);
        }
    }

    while (heap->size > 1) {
        HuffmanNode* left = deleteMinHeap(heap);
        HuffmanNode* right = deleteMinHeap(heap);

        int frequencySum = left->frequency + right->frequency;
        HuffmanNode* parent = createHuffmanNode('\0', frequencySum);
        if (parent == NULL) {
            break;
        }

        parent->left = left;
        parent->right = right;
        insertMinHeap(heap, parent);
    }

    HuffmanNode* root = deleteMinHeap(heap);
    free(heap);

    return root;
}

void freeHuffmanTree(HuffmanNode* root) {
    if (root == NULL) {
        return;
    }

    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);
    free(root);
}
