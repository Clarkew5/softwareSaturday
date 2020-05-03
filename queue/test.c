
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int main(void) {
    queue* q;

    //push one item peek the item and pop item
    printf("push peek pop 1 item:\t");
    q = createQueue();

    push(q, 1);
    if (queueSize(q) != 1) {
        printf("FAIL size was not equal to 1\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q) != 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q);
        return 1;
    }

    deleteQueue(q);
    printf("PASS\n");

    //push two items peek the top and pop both
    printf("push peek pop 2 items:\t");
    q = createQueue();

    push(q, 1);
    push(q, 2);
    if (queueSize(q) != 2) {
        printf("FAIL size was not equal to 2\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q)!= 1) {
        printf("FAIL size was not 1\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q)!= 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q);
        return 1;
    }

    deleteQueue(q);
    printf("PASS\n");

    //push three items peek the top and pop all three
    printf("push peek pop 3 items:\t");
    q = createQueue();

    push(q, 1);
    push(q, 2);
    push(q, 3);

    if (queueSize(q) != 3) {
        printf("FAIL size was not equal to 3\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q)!= 2) {
        printf("FAIL size was not 2\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q)!= 1) {
        printf("FAIL size was not 1\n");
        deleteQueue(q);
        return 1;
    }

    if (peek(q) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteQueue(q);
        return 1;
    }
    if (pop(q) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteQueue(q);
        return 1;
    }
    if (queueSize(q)!= 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q);
        return 1;
    }

    deleteQueue(q);
    printf("PASS\n");

    //memory tests run with valgrind to check
    printf("deleting queue size 0\n");
    q = createQueue();
    deleteQueue(q);

    printf("deleting queue size 1\n");
    q = createQueue();
    push(q, 3);
    deleteQueue(q);

    printf("deleting queue size 2\n");
    q = createQueue();
    push(q, 3);
    push(q, 2);
    deleteQueue(q);

    printf("deleting queue size 3\n");
    q = createQueue();
    push(q, 3);
    push(q, 2);
    push(q, 1);
    deleteQueue(q);

    //stadard out testing manualy verify output is 1 2 3 and queue is empty
    q = createQueue();
    push(q, 1);
    push(q, 2);
    push(q, 3);
    printf("Queues are as easy as ");
    printQueue(q);
    deleteQueue(q);


    q = createQueue();
    printf("\nif nothing is put in the queue then the ");
    printQueue(q);
    deleteQueue(q);

    return 0;
}
