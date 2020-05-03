CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test

queue.o: queue.h queue.c

test: test.c queue.o

clean:
	rm *.o test
