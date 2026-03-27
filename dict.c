#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_SHELF 10

typedef struct Node {
    char key[20];
    int value;
    struct Node *next;
}Node;

typedef struct dict {
    Node* cabinet[NUM_OF_SHELF];
}dict;


unsigned int hash(const char *key) {
    unsigned int hashval = 0;
    while(*key) {
            hashval += *key++;
    }
    return hashval % NUM_OF_SHELF;

}

void dict_set(dict *dic,const char *key,const int value) {
    unsigned const int index = hash(key);

    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) return free(newNode);
    strcpy(newNode->key,key);
    newNode->value = value;

     newNode->next = dic->cabinet[index];
     dic->cabinet[index] = newNode;

}
int dict_get(dict* dic,const char *key) {


    unsigned const int index = hash(key);
    Node* current = dic->cabinet[index];
    while(current != NULL) {
        if(strcmp(current->key,key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return -1;
}


int main() {
    dict di;

    dict_set(&di,"key",8);
    printf("%d",dict_get(&di,"key"));

}