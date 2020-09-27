
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

int main(void) {
    int testArrays[4][5] = {{2, 4, 7, 5, 6},
                            {2, 4, 5, 6, 7},
                            {7, 6, 5, 4, 2},
                            {5, 2, 7, 4, 6}};
    int sortedArray[5] =    {2, 4, 5, 6, 7};

    heap *h;
    for (int i = 0; i < 4; i++) {
        printf("Sort testArray%d: ", i+1);
        h = createHeap();
        for (int j = 0; j < 5; j++){
            push(h, testArrays[i][j], &testArrays[i][j]);
        }
        int testArray[5] = {};
        for (int j = 0; j < 5; j++){
            void* n = pop(h);
            testArray[j] = *((int*)n);
        }
        for (int j = 0; j < 5; j++) {
            if (testArray[j] != sortedArray[j]) {
                printf("FAIL, testArray[%d] was %d instead of %d\n", j, testArray[j], sortedArray[j]);
                deleteHeap(h, 0);
            }
        }
        deleteHeap(h, 0);
        printf("PASS\n");
    }

    //memory leak tests, check in valgrind
    h = createHeap();
    int* a = malloc(sizeof(int));
    *a = 1;
    int* b = malloc(sizeof(int));
    *b = 2;
    int* c = malloc(sizeof(int));
    *c = 3;
    int* d = malloc(sizeof(int));
    *d = 4;
    int* e = malloc(sizeof(int));
    *e = 5;
    int* mallocArray[5] = {a, b, c, d, e};
    for (int i = 0; i < 5; i++) {
        push(h, testArrays[0][i], mallocArray[i]);
    }
    deleteHeap(h, 1);
}
