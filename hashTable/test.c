#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hashTable.h"

int hashFunction(hashTable* hT, void* key) {
    int i = 0;
    long index = 0;
    while (((char*)key)[i] != '\0') {
        index = index << 8;
        index |= ((char*)key)[i];
        i++;
    }
    return index % hT->size;
}

int cmp(void* a, void* b) {
    return strcmp(a, b);
}

int main(void) {
    hashTable* hT;
    printf("Starting tests\n");
    printf("Test 1 key, hash table size 1: ");
    hT = createHashTable(1);
    //insert 1 key no collision
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    //lookup key in hash table
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for key check if updated
    update(hT, hashFunction, cmp, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, hashFunction, cmp, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, hashFunction, cmp, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, hashFunction, cmp, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key, check if gone
    if(removeEnrty(hT, hashFunction, cmp, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    if(lookup(hT, hashFunction, cmp, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test 1 key, hash table size 7: ");
    hT = createHashTable(7);//insert 1 key no collision
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    //lookup key in hash table
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for key check if updated
    update(hT, hashFunction, cmp, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, hashFunction, cmp, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, hashFunction, cmp, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, hashFunction, cmp, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key, check if gone
    if(removeEnrty(hT, hashFunction, cmp, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    if(lookup(hT, hashFunction, cmp, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test insert duplicate key: ");
    hT = createHashTable(1);
    //insert 2 key, with duplicate key, check if errors
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    if (insert(hT, hashFunction, cmp, "key1", "originalValue2") != 1) {
        printf("FAIL: insert duplicate key1 did not return Error\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test 2 key without collision: ");
    hT = createHashTable(2);
    //insert 2 key, no collision
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    insert(hT, hashFunction, cmp, "key2", "originalValue2");
    //lookup first key
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for first key, check if updated
    update(hT, hashFunction, cmp, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup second key
    if (strcmp(lookup(hT, hashFunction, cmp, "key2"), "originalValue2") != 0) {
        printf("FAIL: lookup(key2) did not return 'originalValue2'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for second key, check if updated
    update(hT, hashFunction, cmp, "key2", "updatedVaule2");
    if (strcmp(lookup(hT, hashFunction, cmp, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test 2 key with collision: ");
    hT = createHashTable(1);
    //insert 2 key yes collision
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    insert(hT, hashFunction, cmp, "key2", "originalValue2");
    //lookup key first item in linked list
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update vlaue for first item in linked list, check if updated
    update(hT, hashFunction, cmp, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key second item in linked list
    if (strcmp(lookup(hT, hashFunction, cmp, "key2"), "originalValue2") != 0) {
        printf("FAIL: lookup(key2) did not return 'originalValue2'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update vlaue for second item in linked list, check if updated
    update(hT, hashFunction, cmp, "key2", "updatedVaule2");
    if (strcmp(lookup(hT, hashFunction, cmp, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, hashFunction, cmp, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, hashFunction, cmp, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, hashFunction, cmp, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //remove key second item in linked list, check if gone
    if(removeEnrty(hT, hashFunction, cmp, "key2") != 0) {
        printf("FAIL: removeEnrty(key2) did not return 0\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    if(lookup(hT, hashFunction, cmp, "key2") != NULL) {
        printf("FAIL: lookup(key2) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //insert removed key
    insert(hT, hashFunction, cmp, "key2", "updatedVaule2");
    //remove key first item, check if gone
    if(removeEnrty(hT, hashFunction, cmp, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    if(lookup(hT, hashFunction, cmp, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key for orignal second item in linked list
    if (strcmp(lookup(hT, hashFunction, cmp, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test 3 key collision: ");
    hT = createHashTable(1);
    //insert 3 key all clollide
    insert(hT, hashFunction, cmp, "key1", "originalValue1");
    insert(hT, hashFunction, cmp, "key2", "originalValue2");
    insert(hT, hashFunction, cmp, "key3", "originalValue3");
    //remove second item in linked list, check if gone
    if(removeEnrty(hT, hashFunction, cmp, "key2") != 0) {
        printf("FAIL: removeEnrty(key2) did not return 0\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    if(lookup(hT, hashFunction, cmp, "key2") != NULL) {
        printf("FAIL: lookup(key2) did not return NULL\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key for orignal first item
    if (strcmp(lookup(hT, hashFunction, cmp, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    //lookup key for orignal third item
    if (strcmp(lookup(hT, hashFunction, cmp, "key3"), "originalValue3") != 0) {
        printf("FAIL: lookup(key3) did not return 'originalValue3'\n");
        deleteHashTable(hT, 0, 0);
        return 1;
    }
    deleteHashTable(hT, 0, 0);
    printf("PASS\n");

    printf("Test Memory, check with valgrind:\n");
    char* key1 = calloc(5, sizeof(char));
    char* key2 = calloc(5, sizeof(char));
    char* key3 = calloc(5, sizeof(char));
    char* val1 = calloc(5, sizeof(char));
    char* val2 = calloc(5, sizeof(char));
    char* val3 = calloc(5, sizeof(char));

    hT = createHashTable(2);
    strcpy(key1, "key1");
    strcpy(key2, "key2");
    strcpy(key3, "key3");
    strcpy(val1, "val1");
    strcpy(val2, "val2");
    strcpy(val3, "val3");
    //insert 3 key all clollide
    insert(hT, hashFunction, cmp, key1, val1);
    insert(hT, hashFunction, cmp, key2, val2);
    insert(hT, hashFunction, cmp, key3, val3);
    deleteHashTable(hT, 1, 1);

    val1 = calloc(5, sizeof(char));
    val2 = calloc(5, sizeof(char));
    val3 = calloc(5, sizeof(char));
    hT = createHashTable(2);
    strcpy(val1, "val1");
    strcpy(val2, "val2");
    strcpy(val3, "val3");
    //insert 3 key all clollide
    insert(hT, hashFunction, cmp, "key1", val1);
    insert(hT, hashFunction, cmp, "key2", val2);
    insert(hT, hashFunction, cmp, "key3", val3);
    deleteHashTable(hT, 0, 1);

    key1 = calloc(5, sizeof(char));
    key2 = calloc(5, sizeof(char));
    key3 = calloc(5, sizeof(char));
    strcpy(key1, "key1");
    strcpy(key2, "key2");
    strcpy(key3, "key3");
    hT = createHashTable(2);
    //insert 3 key all clollide
    insert(hT, hashFunction, cmp, key1, "originalValue1");
    insert(hT, hashFunction, cmp, key2, "originalValue2");
    insert(hT, hashFunction, cmp, key3, "originalValue3");
    deleteHashTable(hT, 1, 0);
    return 0;
}
