#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node* head;
} stack;

stack* createStack();
int deleteStack(stack* s);

int stackSize(stack* s);
int peekStack(stack* s);
int printStack(stack* s);

int pushStack(stack* s, int data);
int popStack(stack* s);
