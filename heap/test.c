
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
        h = createHeap();
        for (int j = 0; j < 5; j++){
            push(h, testArrays[i][j], &testArrays[i][j]);
        }
        int testArray[5] = {};
        for (int j = 0; j < 5; j++){
            node * n = pop(h);
            testArray[j] = n->key;
            free(n);
        }
        for (int j = 0; j < 5; j++) {
            if (testArray[j] != sortedArray[j]) {
                printf("FAIL, testArray[%d] was %d instead of %d\n", j, testArray[j], sortedArray[j]);
                deleteHeap(h);
            }
        }
        deleteHeap(h);
        printf("PASS\n");
    }

    //memory leak tests, check in valgrind
    h = createHeap();
    for (int i = 0; i < 5; i++){
        push(h, testArrays[0][i], &testArrays[0][i]);
    }
    deleteHeap(h);
}
