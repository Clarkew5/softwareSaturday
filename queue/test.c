
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void pf(void * data) {
    printf("%d->", *((int*)data));
}

int main(void) {
    queue* q;
    int i = 1;
    int j = 2;
    int k = 3;

    //push one item peek the item and pop item
    printf("push peek pop 1 item:\t");
    q = createQueue();

    pushQueue(q, &i);
    if (queueSize(q) != 1) {
        printf("FAIL size was not equal to 1\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q) != 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q, 0);
        return 1;
    }

    deleteQueue(q, 0);
    printf("PASS\n");

    //push two items peek the top and pop both
    printf("push peek pop 2 items:\t");
    q = createQueue();

    pushQueue(q, &i);
    pushQueue(q, &j);
    if (queueSize(q) != 2) {
        printf("FAIL size was not equal to 2\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q)!= 1) {
        printf("FAIL size was not 1\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q)!= 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q, 0);
        return 1;
    }

    deleteQueue(q, 0);
    printf("PASS\n");

    //push three items peek the top and pop all three
    printf("push peek pop 3 items:\t");
    q = createQueue();

    pushQueue(q, &i);
    pushQueue(q, &j);
    pushQueue(q, &k);

    if (queueSize(q) != 3) {
        printf("FAIL size was not equal to 3\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 1) {
        printf("FAIL peek did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 1) {
        printf("FAIL pop did not equal 1\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q)!= 2) {
        printf("FAIL size was not 2\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 2) {
        printf("FAIL peek did not equal 2\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 2) {
        printf("FAIL pop did not equal 2\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q)!= 1) {
        printf("FAIL size was not 1\n");
        deleteQueue(q, 0);
        return 1;
    }

    if ( *((int*)peekQueue(q)) != 3) {
        printf("FAIL peek did not equal 3\n");
        deleteQueue(q, 0);
        return 1;
    }
    if ( *((int*)popQueue(q)) != 3) {
        printf("FAIL pop did not equal 3\n");
        deleteQueue(q, 0);
        return 1;
    }
    if (queueSize(q)!= 0) {
        printf("FAIL size was not 0\n");
        deleteQueue(q, 0);
        return 1;
    }

    deleteQueue(q, 0);
    printf("PASS\n");

    //memory tests run with valgrind to check
    printf("deleting queue size 0\n");
    q = createQueue();
    deleteQueue(q, 0);

    printf("deleting queue size 1\n");
    q = createQueue();
    pushQueue(q, &k);
    deleteQueue(q, 0);

    printf("deleting queue size 2\n");
    q = createQueue();
    pushQueue(q, &k);
    pushQueue(q, &j);
    deleteQueue(q, 0);

    printf("deleting queue size 3\n");
    q = createQueue();
    pushQueue(q, &k);
    pushQueue(q, &j);
    pushQueue(q, &i);
    deleteQueue(q, 0);

    //memory tests run with valgrind to check
    printf("deleting queue with freeing data size 0\n");
    q = createQueue();
    deleteQueue(q, 0);

    printf("deleting queue with freeing data size 1\n");
    q = createQueue();
    int* kp = malloc(sizeof(int));
    *kp = 3;
    pushQueue(q, (void*)kp);
    deleteQueue(q, 1);

    printf("deleting queue with freeing data size 2\n");
    q = createQueue();

    kp = malloc(sizeof(int));
    *kp = 3;
    int* jp = malloc(sizeof(int));
    *jp = 2;
    pushQueue(q, (void*)kp);
    pushQueue(q, (void*)jp);
    deleteQueue(q, 1);

    printf("deleting queue with freeing data size 3\n");
    q = createQueue();
    kp = malloc(sizeof(int));
    *kp = 3;
    jp = malloc(sizeof(int));
    *jp = 2;
    int* ip = malloc(sizeof(int));
    *ip = 1;
    pushQueue(q, (void*)kp);
    pushQueue(q, (void*)jp);
    pushQueue(q, (void*)ip);
    deleteQueue(q, 1);

    //stadard out testing manualy verify output is 1 2 3 and queue is empty
    q = createQueue();
    kp = malloc(sizeof(int));
    *kp = 1;
    jp = malloc(sizeof(int));
    *jp = 2;
    ip = malloc(sizeof(int));
    *ip = 3;
    pushQueue(q, (void*)kp);
    pushQueue(q, (void*)jp);
    pushQueue(q, (void*)ip);
    printf("Queues are as easy as ");
    printQueue(q, pf);
    deleteQueue(q, 1);


    q = createQueue();
    printf("\nif nothing is put in the queue then the ");
    printQueue(q, NULL);
    deleteQueue(q, 0);
    return 0;
}
