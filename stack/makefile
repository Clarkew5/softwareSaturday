CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test

stack.o: stack.h stack.c

test: test.c stack.o

clean:
	rm *.o test
