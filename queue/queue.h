#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    void* data;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node* head;
    struct node* tail;
} queue;

queue* createQueue();
int deleteQueue(queue* q, int fFlag);

int queueSize(queue* q);
void* peek(queue* q);
/*  DEPRICATED, TODO take in funtion pointer for displaying void pointer
    node->data
int printQueue(queue* q);
*/

int push(queue* q, void* data);
void* pop(queue* q);
