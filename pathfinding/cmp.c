#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "pathfinding.h"

int main(int argc, char *argv[]) {
    srand(time(0));
    int size = atoi(argv[1]);
    int *testArray1 = malloc(size * sizeof(int));
    int *testArray2 = malloc(size * sizeof(int));
    int *testArray3 = malloc(size * sizeof(int));
    int *testArray4 = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int randInt = rand()%size + 1;
        testArray1[i] = randInt;
        testArray2[i] = randInt;
        testArray3[i] = randInt;
        testArray4[i] = randInt;
    }
    clock_t start, end;
    start = clock();
    bubbleSort(testArray1, size);
    end = clock();
    printf("bubbleSort took: %d\n", (int)(end-start));

    start = clock();
    breadthFirstBubbleSort(testArray2, size);
    end = clock();
    printf("breadthFirstBubbleSort took: %d\n", (int)(end-start));

    start = clock();
    depthFirstBubbleSort(testArray3, size);
    end = clock();
    printf("depthFirstBubbleSort took: %d\n", (int)(end-start));

    start = clock();
    aStarBubbleSort(testArray4, size);
    end = clock();
    printf("aStarBubbleSort took: %d\n", (int)(end-start));

}
