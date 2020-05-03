#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node* head;
    struct node* tail;
} queue;

queue* createQueue();
int deleteQueue(queue* q);

int queueSize(queue* q);
int peek(queue* q);
int printQueue(queue* q);

int push(queue* q, int data);
int pop(queue* q);
