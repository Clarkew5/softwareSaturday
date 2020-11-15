#include "stack.h"

stack* createStack() {
    stack* s = malloc(sizeof(stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

int deleteStack(stack* s, int fFlag) {
    if (stackSize(s) > 0) {
        node* cNode = s->head; //current node
        node* nNode = cNode->child; //next node
        if (fFlag == 1) free(cNode->data);
        free(cNode);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            if (fFlag == 1) free(cNode->data);
            free(cNode);
        }
    }
    free(s);
    return 0;
}

int stackSize(stack* s) {
    return s->size;
}

void* peekStack(stack* s){
    return s->head->data;
}

int printStack(stack* s, void printData(void* data)) {
    if (stackSize(s) > 0) {
        struct node* cNode = s->head; //current node
        struct node* nNode = cNode->child; //next node
        printData(cNode->data);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            printData(cNode->data);
        }
        printf("\n");
    } else {
        printf("stack is empty\n");
    }
    return 0;
}

int pushStack(stack* s, void* data) {
    s->size++;
    struct node* n = malloc(sizeof(node));
    n->data = data;
    n->child = s->head;
    s->head = n;
    return 0;
}

void* popStack(stack* s) {
    s->size--;
    void* d = peekStack(s); //data
    node* oldHead = s->head;
    s->head = oldHead->child;
    free(oldHead);
    return d;
}
