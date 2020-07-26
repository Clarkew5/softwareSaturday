#include "pathfinding.h"

int** expandState(int* s, int size) {
    int** es = malloc((size-1) * sizeof(int*));
    for (int i = 0; i < size-1; i++) {
        int* si = malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
            si[j] = s[j];
        int temp = si[i];
        si[i] = si[i+1];
        si[i+1] = temp;
        es[i] = si;
    }
    return es;
}

int hF(hashTable* hT, void* key) {
    unsigned long long index = 0;
    for (int i = 0; i < ((array*)key)->size; i++) {
        index = index << sizeof(int);
        index |= ((array*)key)->array[i];
    }
    return index % hT->size;
}

int cmp(void* a, void* b) {
    for (int i = 0; i < ((array*)a)->size; i++) {
        if (((array*)a)->array[i] != ((array*)b)->array[i])
            return 1;
    }
    return 0;
}

int isSorted(int* s, int size) {
    for (int i = 0; i < size-1; i++) {
        if (s[i] > s[i+1]) {
            return 0;
        }
    }
    return 1;
}

int bubbleSort(int* a, int size) {
    while(isSorted(a, size) != 1) {
        for (int i = 0; i < size-1; i++) {
            if (a[i] > a[i+1]) {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    return 0;
}

int breadthFirstBubbleSort(int* a, int size) {
    queue* frontier = createQueue();
    queue* allStates = createQueue();
    hashTable* visited = createHashTable(size*size*size*2+1);
    int* ac = malloc(size * sizeof(int));
    memcpy(ac, a, size * sizeof(int));
    pushQueue(frontier, (void*) ac);
    pushQueue(allStates, (void*) ac);
    array* arrayA = malloc(sizeof(array));
    arrayA->array = ac;
    arrayA->size = size;
    insert(visited, hF, cmp, (void*) arrayA, "visited");
    while (queueSize(frontier) != 0) {
        int* s = (int*) popQueue(frontier);
        int** es = expandState(s, size);
        for (int i = 0; i < size-1; i++) {
            if(isSorted(es[i], size) == 1) {
                memcpy(a, es[i], size * sizeof(int));
                for(int j = i; j < size-1; j++) free(es[j]);
                free(es);
                deleteQueue(frontier, 0);
                deleteQueue(allStates, 1);
                deleteHashTable(visited, 1, 0);
                return 0;
            } else {
                array* arrayES = malloc(sizeof(array));
                arrayES->array = es[i];
                arrayES->size = size;
                if (lookup(visited, hF, cmp, (void*) arrayES) == NULL){
                    insert(visited, hF, cmp, (void*) arrayES, "visited");
                    pushQueue(frontier, (void*) es[i]);
                    pushQueue(allStates, (void*) es[i]);
                } else {
                    free(es[i]);
                    free(arrayES);
                }
            }
        }
        free(es);
    }
    return 1;
}

int depthFirstBubbleSort(int* a, int size) {
    stack* frontier = createStack();
    queue* allStates = createQueue();
    hashTable* visited = createHashTable(size*size*size*2+1);
    int* ac = malloc(size * sizeof(int));
    memcpy(ac, a, size * sizeof(int));
    pushStack(frontier, (void*) ac);
    pushQueue(allStates, (void*) ac);
    array* arrayA = malloc(sizeof(array));
    arrayA->array = ac;
    arrayA->size = size;
    insert(visited, hF, cmp, (void*) arrayA, "visited");
    while(stackSize(frontier) != 0) {
        int* s = (int*) popStack(frontier);
        int** es = expandState(s, size);
        for (int i = 0; i < size-1; i++) {
            if(isSorted(es[i], size) == 1) {
                memcpy(a, es[i], size * sizeof(int));
                for(int j = i; j < size-1; j++) free(es[j]);
                free(es);
                deleteStack(frontier, 0);
                deleteQueue(allStates, 1);
                deleteHashTable(visited, 1, 0);
                return 0;
            } else {
                array* arrayES = malloc(sizeof(array));
                arrayES->array = es[i];
                arrayES->size = size;
                if (lookup(visited, hF, cmp, (void*) arrayES) == NULL){
                    insert(visited, hF, cmp, (void*) arrayES, "visited");
                    pushStack(frontier, (void*) es[i]);
                    pushQueue(allStates, (void*) es[i]);
                } else {
                    free(es[i]);
                    free(arrayES);
                }
            }
        }
        free(es);
    }
    return 1;
}

int hueristic(int* a, int size) {
    int h = size;
    for (int i = 0; i < size-1; i++) {
        if (a[i] <= a[i+1]) h--;
    }
    return h;
}

int aStarBubbleSort(int* a, int size) {
    heap* frontier = createHeap();
    queue* allStates = createQueue();
    hashTable* visited = createHashTable(size*size*size*2+1);
    int* ac = malloc(size * sizeof(int));
    memcpy(ac, a, size * sizeof(int));
    int h = hueristic(ac, size);
    pushQueue(allStates, (void*) ac);
    frontierNode* frontierNodeA = malloc(sizeof(frontierNode));
    frontierNodeA->array = ac;
    frontierNodeA->steps = 0;
    pushHeap(frontier, h, (void*) frontierNodeA);
    array* arrayA = malloc(sizeof(array));
    arrayA->array = ac;
    arrayA->size = size;
    int *f = malloc(sizeof(int));
    *f = h;
    insert(visited, hF, cmp, (void*) arrayA, (void*)f);
    while (heapSize(frontier) != 0) {
        frontierNode* s = (frontierNode*) popHeap(frontier);
        int g = s->steps + 1;
        int** es = expandState(s->array, size);
        free(s);
        for (int i = 0; i < size-1; i++) {
            if(isSorted(es[i], size) == 1) {
                memcpy(a, es[i], size * sizeof(int));
                for(int j = i; j < size-1; j++) free(es[j]);
                free(es);
                deleteHeap(frontier, 1);
                deleteQueue(allStates, 1);
                deleteHashTable(visited, 1, 1);
                return 0;
            } else {
                array* arrayES = malloc(sizeof(array));
                arrayES->array = es[i];
                arrayES->size = size;
                frontierNode* frontierNodeES = malloc(sizeof(frontierNode));
                frontierNodeES->array = es[i];
                frontierNodeES->steps = g;
                h = hueristic(es[i], size);
                if (lookup(visited, hF, cmp, (void*) arrayES) == NULL) {
                    int *f = malloc(sizeof(int));
                    *f = h+g;
                    insert(visited, hF, cmp, (void*) arrayES, (void*) f);
                    pushHeap(frontier, h+g, (void*) frontierNodeES);
                    pushQueue(allStates, (void*) es[i]);
                } else if (*(int*)lookup(visited, hF, cmp, (void*) arrayES) > h+g) {
                    int* f = malloc(sizeof(int));
                    *f = h+g;
                    update(visited, hF, cmp, (void*) arrayES, (void*) f, 1);
                    pushHeap(frontier, h+g, (void*) frontierNodeES);
                    pushQueue(allStates, (void*) es[i]);
                    free(arrayES);
                } else {
                    free(es[i]);
                    free(arrayES);
                    free(frontierNodeES);
                }
            }
        }
        free(es);
    }
    return 1;
}
