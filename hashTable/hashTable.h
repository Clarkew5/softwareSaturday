#ifndef HASHTABLE
#define HASHTABLE

#include <stdlib.h>
#include <stdio.h>

typedef struct htNode {
    void* key;
    void* value;
    struct htNode* child;
} htNode;

typedef struct {
    int size;
    struct htNode** array;
} hashTable;

hashTable* createHashTable(int size);
int deleteHashTable(hashTable* hT, int fkFlag, int fdFlag);

int insert(hashTable* hT, int hashFun(hashTable* hT, void* key), int compare(void* a, void* b), char* key, char* value);
char* lookup(hashTable* hT, int hashFun(hashTable* hT, void* key), int compare(void* a, void* b), char* key);
int update(hashTable* hT, int hashFun(hashTable* hT, void* key), int compare(void* a, void* b), char* key, char* value);
int removeEnrty(hashTable* hT, int hashFun(hashTable* hT, void* key), int compare(void* a, void* b), char* key);

#endif
