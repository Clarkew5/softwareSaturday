CC=gcc
CFLAGS=-Wall -std=c99 -g

.PHONY: all clean

all: test cmp

../heap/heap.o: ../heap/heap.h ../heap/heap.c

../queue/queue.o: ../queue/queue.h ../queue/queue.c

../hashTable/hashTable.o: ../hashTable/hashTable.h ../hashTable/hashTable.c

../stack/stack.o: ../stack/stack.h ../stack/stack.c

pathfinding.o: pathfinding.h pathfinding.c

test: test.c pathfinding.o ../queue/queue.o ../hashTable/hashTable.o ../heap/heap.o ../stack/stack.o

cmp: cmp.c pathfinding.o ../queue/queue.o ../hashTable/hashTable.o ../heap/heap.o ../stack/stack.o

clean:
	rm *.o ../heap/*.o ../queue/*.o ../hashTable/*.o test cmp
