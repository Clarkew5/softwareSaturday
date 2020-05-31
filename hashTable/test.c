#include <stdlib.h>
#include <stdio.h>
#include "hashTable.h"

int main(void) {
    hashTable* hT;
    printf("Starting tests\n");
    printf("Test 1 key, hash table size 1: ");
    hT = createHashTable(1);
    //insert 1 key no collision
    insert(hT, "key1", "originalValue1");
    //lookup key in hash table
    if (strcmp(lookup(hT, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for key check if updated
    update(hT, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key, check if gone
    if(removeEnrty(hT, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT);
        return 1;
    }
    if(lookup(hT, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    printf("Test 1 key, hash table size 7: ");
    hT = createHashTable(7);//insert 1 key no collision
    insert(hT, "key1", "originalValue1");
    //lookup key in hash table
    if (strcmp(lookup(hT, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for key check if updated
    update(hT, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key, check if gone
    if(removeEnrty(hT, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT);
        return 1;
    }
    if(lookup(hT, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    printf("Test insert duplicate key: ");
    hT = createHashTable(1);
    //insert 2 key, with duplicate key, check if errors
    insert(hT, "key1", "originalValue1");
    if (insert(hT, "key1", "originalValue2") != 1) {
        printf("FAIL: insert duplicate key1 did not return Error\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    printf("Test 2 key without collision: ");
    hT = createHashTable(2);
    //insert 2 key, no collision
    insert(hT, "key1", "originalValue1");
    insert(hT, "key2", "originalValue2");
    //lookup first key
    if (strcmp(lookup(hT, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for first key, check if updated
    update(hT, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup second key
    if (strcmp(lookup(hT, "key2"), "originalValue2") != 0) {
        printf("FAIL: lookup(key2) did not return 'originalValue2'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for second key, check if updated
    update(hT, "key2", "updatedVaule2");
    if (strcmp(lookup(hT, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    printf("Test 2 key with collision: ");
    hT = createHashTable(1);
    //insert 2 key yes collision
    insert(hT, "key1", "originalValue1");
    insert(hT, "key2", "originalValue2");
    //lookup key first item in linked list
    if (strcmp(lookup(hT, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update vlaue for first item in linked list, check if updated
    update(hT, "key1", "updatedVaule1");
    if (strcmp(lookup(hT, "key1"), "updatedVaule1") != 0) {
        printf("FAIL: lookup(key1) did not return 'updatedVaule1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key second item in linked list
    if (strcmp(lookup(hT, "key2"), "originalValue2") != 0) {
        printf("FAIL: lookup(key2) did not return 'originalValue2'\n");
        deleteHashTable(hT);
        return 1;
    }
    //update vlaue for second item in linked list, check if updated
    update(hT, "key2", "updatedVaule2");
    if (strcmp(lookup(hT, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key not in hash table, check if errors
    if(lookup(hT, "keyX") != NULL) {
        printf("FAIL: lookup(keyX) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //update value for key not in hash table, check if errors
    if(update(hT, "keyX", "ERROR") != 1) {
        printf("FAIL: update(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key not in hash table, check if errors
    if(removeEnrty(hT, "keyX") != 1) {
        printf("FAIL: removeEnrty(keyX) did not return 1\n");
        deleteHashTable(hT);
        return 1;
    }
    //remove key second item in linked list, check if gone
    if(removeEnrty(hT, "key2") != 0) {
        printf("FAIL: removeEnrty(key2) did not return 0\n");
        deleteHashTable(hT);
        return 1;
    }
    if(lookup(hT, "key2") != NULL) {
        printf("FAIL: lookup(key2) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //insert removed key
    insert(hT, "key2", "updatedVaule2");
    //remove key first item, check if gone
    if(removeEnrty(hT, "key1") != 0) {
        printf("FAIL: removeEnrty(key1) did not return 0\n");
        deleteHashTable(hT);
        return 1;
    }
    if(lookup(hT, "key1") != NULL) {
        printf("FAIL: lookup(key1) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key for orignal second item in linked list
    if (strcmp(lookup(hT, "key2"), "updatedVaule2") != 0) {
        printf("FAIL: lookup(key2) did not return 'updatedVaule2'\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    printf("Test 1 key no collision: ");
    hT = createHashTable(1);
    //insert 3 key all clollide
    insert(hT, "key1", "originalValue1");
    insert(hT, "key2", "originalValue2");
    insert(hT, "key3", "originalValue3");
    //remove second item in linked list, check if gone
    if(removeEnrty(hT, "key2") != 0) {
        printf("FAIL: removeEnrty(key2) did not return 0\n");
        deleteHashTable(hT);
        return 1;
    }
    if(lookup(hT, "key2") != NULL) {
        printf("FAIL: lookup(key2) did not return NULL\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key for orignal first item
    if (strcmp(lookup(hT, "key1"), "originalValue1") != 0) {
        printf("FAIL: lookup(key1) did not return 'originalValue1'\n");
        deleteHashTable(hT);
        return 1;
    }
    //lookup key for orignal third item
    if (strcmp(lookup(hT, "key3"), "originalValue3") != 0) {
        printf("FAIL: lookup(key3) did not return 'originalValue3'\n");
        deleteHashTable(hT);
        return 1;
    }
    deleteHashTable(hT);
    printf("PASS\n");

    return 0;
}
