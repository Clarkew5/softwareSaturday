#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../queue/queue.h"
#include "../hashTable/hashTable.h"
#include "../heap/heap.h"
#include "../stack/stack.h"

typedef struct {
    int size;
    int* array;
} array;

typedef struct {
    int* array;
    int steps;
} frontierNode;

int** expandState(int* s, int size);
int isSorted(int* s, int size);
int heuristic(int* s, int size);
int hF(hashTable* hT, void* key);
int cmp(void* a, void* b);

int bubbleSort(int* a, int size);
int breadthFirstBubbleSort(int* a, int size);
int depthFirstBubbleSort(int* a, int size);
int aStarBubbleSort(int* a, int size);
