CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test

hashTable.o: hashTable.h hashTable.c

test: test.c hashTable.o

clean:
	rm *.o test
