#include "queue.h"

queue* createQueue() {
    queue* q = malloc(sizeof(queue));
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int deleteQueue(queue* q, int fFlag) {
    if (queueSize(q) > 0) {
        node* cNode = q->head; //current node
        node* nNode = cNode->child; //next node
        if(fFlag == 1) free(cNode->data);
        free(cNode);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            if(fFlag == 1) free(cNode->data);
            free(cNode);
        }
    }
    free(q);
    return 0;
}

int queueSize(queue* q) {
    return q->size;
}

void* peek(queue* q) {
    return q->head->data;
}

/*  DEPRICATED, TODO take in funtion pointer for displaying void pointer
    node->data
int printQueue(queue* q) {
    if (queueSize(q) > 0) {
        node* cNode = q->head; //current node
        node* nNode = cNode->child; //next node
        printf("%d ", cNode->data);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            printf("%d ", cNode->data);
        }
    } else {
        printf("queue is empty\n");
    }
    return 0;
}
*/

int push(queue* q, void* data) {
    q->size++;
    struct node* n = malloc(sizeof(node));
    n->data = data;
    n->child = NULL;
    if (q->head == NULL) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->child = n;
        q->tail = n;
    }
    return 0;
}

void* pop(queue* q) {
    q->size--;
    void* d = peek(q); //data
    node* oldHead = q->head;
    q->head = oldHead->child;
    free(oldHead);
    return d;
}
