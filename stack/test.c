#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(void) {
    stack* s;

    //push one item peek the item and pop item
    printf("push peek pop 1 item:\t");
    s = createStack();

    pushStack(s, 3);
    if (stackSize(s) != 1) {
        printf("FAIL size was not equal to 1\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s)!= 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s);
        return 1;
    }

    deleteStack(s);
    printf("PASS\n");

    //push two items peek the top and pop both
    printf("push peek pop 2 items:\t");
    s = createStack();

    pushStack(s, 3);
    pushStack(s, 2);
    if (stackSize(s) != 2) {
        printf("FAIL size was not equal to 2\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s) != 1) {
        printf("FAIL size was not 1\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s)!= 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s) != 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s);
        return 1;
    }

    deleteStack(s);
    printf("PASS\n");

    //push three items peek the top and pop all three
    printf("push peek pop 3 items:\t");
    s = createStack();

    pushStack(s, 3);
    pushStack(s, 2);
    pushStack(s, 1);
    if (stackSize(s) != 3) {
        printf("FAIL size was not equal to 3\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s) != 2) {
        printf("FAIL size was not 2\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s) != 1) {
        printf("FAIL size was not 1\n");
        deleteStack(s);
        return 1;
    }

    if (peekStack(s)!= 3) {
        printf("FAIL peek did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (popStack(s) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteStack(s);
        return 1;
    }
    if (stackSize(s) != 0) {
        printf("FAIL size was not 0\n");
        deleteStack(s);
        return 1;
    }

    deleteStack(s);
    printf("PASS\n");

    //memory tests run with valgrind to check
    printf("deleting stack size 0\n");
    s = createStack();
    deleteStack(s);

    printf("deleting stack size 1\n");
    s = createStack();
    pushStack(s, 3);
    deleteStack(s);

    printf("deleting stack size 2\n");
    s = createStack();
    pushStack(s, 3);
    pushStack(s, 2);
    deleteStack(s);

    //stadard out testing manualy verify output is 1 2 3 and Stack is empty
    s = createStack();
    pushStack(s, 3);
    pushStack(s, 2);
    pushStack(s, 1);
    printf("stacks are as easy as ");
    printStack(s);
    deleteStack(s);


    s = createStack();
    printf("\nif nothing is put in the stack then the ");
    printStack(s);
    deleteStack(s);

    return 0;
}
