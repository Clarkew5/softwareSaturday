#ifndef HEAP
#define HEAP

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int key;
    void* data;
} hNode;

typedef struct treeLevel {
    int arraySize;
    int insertIndex;
    hNode** data;
    struct treeLevel* parent;
    struct treeLevel* child;
} treeLevel;

typedef struct {
    int size;
    treeLevel* head;
    treeLevel* bottomLevel;
} heap;

heap* createHeap();
int deleteHeap(heap* h, int fFlag);
int peekHeap(heap* h);
int heapSize(heap* h);

int pushHeap(heap* h, int key, void* data);
int upHeap(heap* h);
void* popHeap(heap* h);
int downHeap(heap* h);

int printHeap(heap* h);

#endif
