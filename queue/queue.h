#ifndef QUEUE
#define QUEUE

#include <stdlib.h>
#include <stdio.h>

typedef struct qNode {
    void* data;
    struct qNode* child;
} qNode;

typedef struct {
    int size;
    struct qNode* head;
    struct qNode* tail;
} queue;

queue* createQueue();
int deleteQueue(queue* q, int fFlag);

int queueSize(queue* q);
void* peekQueue(queue* q);
int printQueue(queue* q, void printData(void* data));

int pushQueue(queue* q, void* data);
void* popQueue(queue* q);

#endif
