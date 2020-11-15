#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void printInt(void* i) {
    printf("%d ", *((int*)i));
}

int main(void) {
    stack* s;
    int one = 1;
    int two = 2;
    int three = 3;
    //push one item peek the item and pop item
    printf("push peek pop 1 item:\t");
    s = createStack();

    pushStack(s, &three);
    if (stackSize(s) != 1) {
        printf("FAIL size was not equal to 1\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s)!= 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s, 0);
        return 1;
    }

    deleteStack(s, 0);
    printf("PASS\n");

    //push two items peek the top and pop both
    printf("push peek pop 2 items:\t");
    s = createStack();

    pushStack(s, &three);
    pushStack(s, &two);
    if (stackSize(s) != 2) {
        printf("FAIL size was not equal to 2\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s) != 1) {
        printf("FAIL size was not 1\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s) != 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s, 0);
        return 1;
    }

    deleteStack(s, 0);
    printf("PASS\n");

    //push three items peek the top and pop all three
    printf("push peek pop 3 items:\t");
    s = createStack();

    pushStack(s, &three);
    pushStack(s, &two);
    pushStack(s, &one);
    if (stackSize(s) != 3) {
        printf("FAIL size was not equal to 3\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s) != 2) {
        printf("FAIL size was not 2\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s) != 1) {
        printf("FAIL size was not 1\n");
        deleteStack(s, 0);
        return 1;
    }

    if (*((int*)peekStack(s)) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (*((int*)popStack(s)) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s, 0);
        return 1;
    }
    if (stackSize(s) != 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s, 0);
        return 1;
    }

    deleteStack(s, 0);
    printf("PASS\n");

    //memory tests run with valgrind to check
    printf("deleting stack size 0\n");
    s = createStack();
    deleteStack(s, 0);

    printf("deleting stack size 1\n");
    s = createStack();
    pushStack(s, &three);
    deleteStack(s, 0);

    printf("deleting stack size 2\n");
    s = createStack();
    pushStack(s, &three);
    pushStack(s, &two);
    deleteStack(s, 0);

    //stadard out testing manualy verify output is 1 2 3 and Stack is empty
    s = createStack();
    pushStack(s, &three);
    pushStack(s, &two);
    pushStack(s, &one);
    printf("stacks are as easy as ");
    printStack(s, printInt);
    deleteStack(s, 0);


    s = createStack();
    printf("\nif nothing is put in the stack then the ");
    printStack(s, printInt);
    deleteStack(s, 0);

    return 0;
}
