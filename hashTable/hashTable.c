#include "hashTable.h"

hashTable* createHashTable(int size) {
    hashTable* hT = malloc(sizeof(hashTable));
    hT->size = size;
    hT->array = calloc(size, sizeof(htNode));
    return hT;
}

int deleteHashTable(hashTable* hT, int fkFlag, int fdFlag) {
    for (int i = 0; i < hT->size; i++) {
        if (hT->array[i] != NULL) {
            htNode* cNode = hT->array[i]; //current node
            htNode* nNode = hT->array[i]->child; //next node
            if (fkFlag == 1) free(cNode->key);
            if (fdFlag == 1) free(cNode->value);
            free(cNode);

            while (nNode != NULL) {
                cNode = nNode;
                nNode = cNode->child;
                if (fkFlag == 1) free(cNode->key);
                if (fdFlag == 1) free(cNode->value);
                free(cNode);
            }
        }
    }
    free(hT->array);
    free(hT);
    return 0;
}

int insert(hashTable* hT, int hashFun(hashTable* hT,  void * key), int compare(void* a,  void* b), char* key, char* value) {
    htNode* iNode = malloc(sizeof(htNode)); //insert node
    iNode->key = key;
    iNode->value = value;
    iNode->child = NULL;

    int index = hashFun(hT, key);
    if (hT->array[index] == NULL) {
        hT->array[index] = iNode;
    } else {
        htNode* pNode = NULL; //previous node
        htNode* cNode = hT->array[index]; //current node
        do {
            if (compare(cNode->key, key) == 0) {
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

char* lookup(hashTable* hT, int hashFun(hashTable* hT, void * key), int compare(void* a, void* b), char* key) {
    int index = hashFun(hT, key);
    if (hT->array[index] == NULL) {
        return NULL;
    } else {
        htNode* cNode = hT->array[index]; //current node
        while (compare(cNode->key, key) != 0 && cNode->child != NULL)
            cNode = cNode->child;

        if (compare(cNode->key, key) == 0) {
            return cNode->value;
        } else {
            return NULL;
        }
    }
}

int update(hashTable* hT, int hashFun(hashTable* hT, void * key), int compare(void* a, void* b), char* key, char* value) {
    int index = hashFun(hT, key);
    if (hT->array[index] == NULL) {
        return 1;
    } else {
        htNode* cNode = hT->array[index]; //current node
        do {
            if (compare(cNode->key, key) == 0) {
                cNode->value = value;
                return 0;
            }
            cNode = cNode->child;
        } while (cNode != NULL);
        return 1;
    }
    return 0;
}

int removeEnrty(hashTable* hT, int hashFun(hashTable* hT, void * key), int compare(void* a, void* b), char* key) {
    int index = hashFun(hT, key);
    if (hT->array[index] == NULL) {
        return 1;
    } else if (compare(hT->array[index]->key, key) == 0) {
        htNode* tNode = hT->array[index]; //temporary node
        hT->array[index] = hT->array[index]->child;
        free(tNode);
        return 0;
    } else {
        htNode* pNode = hT->array[index]; //previous node
        htNode* cNode = pNode->child; //current node

        while (cNode != NULL) {
            if (compare(cNode->key, key) == 0) {
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
