#include "hashTable.h"

int hashFunction(hashTable* hT, char* key) {
    int i = 0;
    long index = 0;
    while (key[i] != '\0') {
        index = index << 8;
        index |= key[i];
        i++;
    }
    return index % hT->size;
}

hashTable* createHashTable(int size) {
    hashTable* hT = malloc(sizeof(hashTable));
    hT->size = size;
    hT->array = calloc(size, sizeof(node));
    return hT;
}

int deleteHashTable(hashTable* hT) {
    for (int i = 0; i < hT->size; i++) {
        if (hT->array[i] != NULL) {
            node* cNode = hT->array[i]; //current node
            node* nNode = hT->array[i]->child; //next node
            free(cNode);

            while (nNode != NULL) {
                cNode = nNode;
                nNode = cNode->child;
                free(cNode);
            }
        }
    }
    free(hT->array);
    free(hT);
    return 0;
}

int insert(hashTable* hT, char* key, char* value) {
    node* iNode = malloc(sizeof(node)); //insert node
    iNode->key = key;
    iNode->value = value;
    iNode->child = NULL;

    int index = hashFunction(hT, key);
    if (hT->array[index] == NULL) {
        hT->array[index] = iNode;
    } else {
        node* pNode = NULL; //previous node
        node* cNode = hT->array[index]; //current node
        do {
            if (strcmp(cNode->key, key) == 0) {
                printf("Error: duplicate key found\n");
                free(iNode);
                return 1;
            }
            pNode = cNode;
            cNode = cNode->child;
        } while (cNode != NULL);
        pNode->child = iNode;
    }
    return 0;
}

char* lookup(hashTable* hT, char* key) {
    int index = hashFunction(hT, key);
    if (hT->array[index] == NULL) {
        return NULL;
    } else {
        node* cNode = hT->array[index]; //current node
        while (strcmp(cNode->key, key) != 0 && cNode->child != NULL)
            cNode = cNode->child;

        if (strcmp(cNode->key, key) == 0) {
            return cNode->value;
        } else {
            return NULL;
        }
    }
}

int update(hashTable* hT, char* key, char* value) {
    int index = hashFunction(hT, key);
    if (hT->array[index] == NULL) {
        return 1;
    } else {
        node* cNode = hT->array[index]; //current node
        do {
            if (strcmp(cNode->key, key) == 0) {
                cNode->value = value;
                return 0;
            }
            cNode = cNode->child;
        } while (cNode != NULL);
        return 1;
    }
    return 0;
}

int removeEnrty(hashTable* hT, char* key) {
    int index = hashFunction(hT, key);
    if (hT->array[index] == NULL) {
        return 1;
    } else if (strcmp(hT->array[index]->key, key) == 0) {
        node* tNode = hT->array[index]; //temporary node
        hT->array[index] = hT->array[index]->child;
        free(tNode);
        return 0;
    } else {
        node* pNode = hT->array[index]; //previous node
        node* cNode = pNode->child; //current node

        while (cNode != NULL) {
            if (strcmp(cNode->key, key) == 0) {
                pNode->child = cNode->child;
                free(cNode);
                return 0;
            }
            pNode = cNode;
            cNode = cNode->child;
        }
        return 1;
    }
}