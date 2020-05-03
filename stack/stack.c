#include "stack.h"

stack* createStack() {
    stack* s = malloc(sizeof(stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

int deleteStack(stack* s) {
    if (stackSize(s) > 0) {
        node* cNode = s->head; //current node
        node* nNode = cNode->child; //next node
        free(cNode);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            free(cNode);
        }
    }
    free(s);
    return 0;
}

int stackSize(stack* s) {
    return s->size;
}

int peek(stack* s){
    return s->head->data;
}

int printStack(stack* s) {
    if (stackSize(s) > 0) {
        struct node* cNode = s->head; //current node
        struct node* nNode = cNode->child; //next node
        printf("%d ", cNode->data);

        while (nNode != NULL) {
            cNode = nNode;
            nNode = cNode->child;
            printf("%d ", cNode->data);
        }
        printf("\n");
    } else {
        printf("stack is empty\n");
    }
    return 0;
}

int push(stack* s, int data) {
    s->size++;
    struct node* n = malloc(sizeof(node));
    n->data = data;
    n->child = s->head;
    s->head = n;
    return 0;
}

int pop(stack* s) {
    s->size--;
    int d = peek(s); //data
    node* oldHead = s->head;
    s->head = oldHead->child;
    free(oldHead);
    return d;
}
