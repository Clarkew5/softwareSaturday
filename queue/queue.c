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
        qNode* cNode = q->head; //current node
        qNode* nNode = cNode->child; //next node
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

void* peekQueue(queue* q) {
    return q->head->data;
}

int printQueue(queue* q, void printData(void* data)) {
    if (queueSize(q) > 0) {
        qNode* cNode = q->head; //current node
        qNode* nNode = cNode->child; //next node
        printData(cNode->data);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            printData(cNode->data);
        }
    } else {
        printf("queue is empty\n");
    }
    return 0;
}

int pushQueue(queue* q, void* data) {
    q->size++;
    struct qNode* n = malloc(sizeof(qNode));
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

void* popQueue(queue* q) {
    q->size--;
    void* d = peekQueue(q); //data
    qNode* oldHead = q->head;
    q->head = oldHead->child;
    free(oldHead);
    return d;
}
