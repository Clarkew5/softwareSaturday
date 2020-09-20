#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    void* key;
    void* value;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node** array;
} hashTable;

hashTable* createHashTable(int size);
int deleteHashTable(hashTable* hT);

int insert(hashTable* hT, int (hashFun)(hashTable* hT, void* key), int compare(void* a, void* b), char* key, char* value);
char* lookup(hashTable* hT, int (hashFun)(hashTable* hT, void* key), int compare(void* a, void* b), char* key);
int update(hashTable* hT, int (hashFun)(hashTable* hT, void* key), int compare(void* a, void* b), char* key, char* value);
int removeEnrty(hashTable* hT, int (hashFun)(hashTable* hT, void* key), int compare(void* a, void* b), char* key);
