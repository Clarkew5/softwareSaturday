#include <stdlib.h>
#include <stdio.h>
#include "pathfinding.h"

int testExpandState();
int testIsSorted();
int testBubbleSort();
int testBreadthFirstBubbleSort();
int testDepthFirstBubbleSort();
int testAStarBubbleSort();

int main(void) {
    printf("expandState: ");
    testExpandState() == 0 ? printf("PASS\n") : printf("FAIL\n");

    printf("isSorted: ");
    testIsSorted() == 0 ? printf("PASS\n") : printf("FAIL\n");

    printf("testBubbleSort: ");
    testBubbleSort() == 0 ? printf("PASS\n") : printf("FAIL\n");

    printf("testBreadthFirstBubbleSort: ");
    testBreadthFirstBubbleSort() == 0 ? printf("PASS\n") : printf("FAIL\n");

    printf("testDepthFirstBubbleSort: ");
    testDepthFirstBubbleSort() == 0 ? printf("PASS\n") : printf("FAIL\n");

    printf("testAStarBubbleSort:" );
    testAStarBubbleSort() == 0 ? printf("PASS\n") : printf("FAIL\n");
}

int testExpandState() {
    int inputArray[5] = {1,2,3,4,5};
    int outputArray[4][5] = {
        {2,1,3,4,5},
        {1,3,2,4,5},
        {1,2,4,3,5},
        {1,2,3,5,4}
    };
    int** testArray = expandState(inputArray, 5);
    for(int i=0; i<4; i++) {
        for (int j=0; j<5; j++) {
            if (outputArray[i][j] != testArray[i][j]) {
                return 1;
            }
        }
        free(testArray[i]);
    }
    free(testArray);
    return 0;
}

int testIsSorted() {
    int inputArrays[5][5] = {
        {2,1,3,4,5},
        {1,3,2,4,5},
        {1,2,4,3,5},
        {1,2,3,5,4},
        {1,2,3,4,5}
    };
    int outputs[5] = {0,0,0,0,1};
    for (int i = 0; i < 5; i++) {
        if (isSorted(inputArrays[i], 5) != outputs[i]) {
            return 1;
        }
    }
    return 0;
}

int testBubbleSort() {
    int inputArray[5] = {5,4,3,2,1};
    int outputArray[5] = {1,2,3,4,5};
    bubbleSort(inputArray, 5);
    for (int i = 0; i < 5; i++) {
        if (inputArray[i] != outputArray[i]) {
            return 1;
        }
    }
    return 0;
}

int testBreadthFirstBubbleSort() {
    int inputArray[5] = {5,4,3,2,1};
    int outputArray[5] = {1,2,3,4,5};
    breadthFirstBubbleSort(inputArray, 5);
    for (int i = 0; i < 5; i++) {
        if (inputArray[i] != outputArray[i]) {
            return 1;
        }
    }
    return 0;
}

int testDepthFirstBubbleSort() {
    int inputArray[5] = {5,4,3,2,1};
    int outputArray[5] = {1,2,3,4,5};
    depthFirstBubbleSort(inputArray, 5);
    for (int i = 0; i < 5; i++) {
        if (inputArray[i] != outputArray[i]) {
            return 1;
        }
    }
    return 0;
}

int testAStarBubbleSort() {
    int inputArray[5] = {5,4,3,2,1};
    int outputArray[5] = {1,2,3,4,5};
    aStarBubbleSort(inputArray, 5);
    for (int i = 0; i < 5; i++) {
        if (inputArray[i] != outputArray[i]) {
            return 1;
        }
    }
    return 0;
}
