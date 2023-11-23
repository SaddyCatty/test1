#include <stdio.h>
#include <string.h>
#include "map.h"

void assignAdjacencyMatrix(int a[][Elem], int elem) {
    int counter;
    char decide;
    for (int i = 0; i < elem; i++) {
        counter = 1;
        do {
            printf("%d号元素是否与%d之间连通？(y/n)\n", (i + 1), counter);
            getchar();
            decide = getchar();
            if (decide == 'y' || decide == 'Y') {
                a[i][counter - 1] = 1;
                printf("stored!\n");
            }
            counter++;
        } while (counter <= elem);
    }
}

void printMatrix(int a[][Elem], int elem) {
    for (int i = 0; i < elem; i++) {
        for (int j = 0; j < elem; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

