CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test

heap.o: heap.h heap.c

test: test.c heap.o

clean:
	rm *.o test
