#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    void* data;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node* head;
} stack;

stack* createStack();
int deleteStack(stack* s, int fFlag);

int stackSize(stack* s);
void* peekStack(stack* s);
int printStack(stack* s, void printData(void* data));

int pushStack(stack* s, void* data);
void* popStack(stack* s);
