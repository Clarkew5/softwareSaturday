#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
    char* key;
    char* value;
    struct node* child;
} node;

typedef struct {
    int size;
    struct node** array;
} hashTable;

int hashFunction(hashTable* hT, char* key);

hashTable* createHashTable(int size);
int deleteHashTable(hashTable* hT);

int insert(hashTable* hT, char* key, char* value);
char* lookup(hashTable* hT, char* key);
int update(hashTable* hT, char* key, char* value);
int removeEnrty(hashTable* hT, char* key);
