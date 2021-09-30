#include <stdbool.h>

#ifndef collection_h
#define collection_h

typedef struct LinkedList {
    struct Node *first;
    struct Node *last;

    int size;
} LinkedList;

typedef struct Node {
    void *value;

    struct Node *prev;
    struct Node *next;
} Node;

void collection_linked_list_append(LinkedList *list, void *value);

void *collection_linked_list_get(LinkedList *list, int index);

void *collection_linked_list_remove(LinkedList *list, int index);

bool collection_linked_list_contains(LinkedList *list, void *value);

#endif /* collection_h */
