#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int key;
    void* data;
} node;

typedef struct treeLevel {
    int arraySize;
    int insertIndex;
    node** data;
    struct treeLevel* parent;
    struct treeLevel* child;
} treeLevel;

typedef struct {
    treeLevel* head;
    treeLevel* bottomLevel;
} heap;

heap* createHeap();
int deleteHeap(heap* h);

int swap(treeLevel* tl1, int i1, treeLevel* tl2, int i2);
int peek(heap* h);

int push(heap* h, int key, void* data);
int upHeap(heap* h);
node* pop(heap* h);
int downHeap(heap* h);

int printHeap(heap* h);
