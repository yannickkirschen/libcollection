#include <stdlib.h>
#include "collection.h"

void collection_linked_list_append(LinkedList *list, void *value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;

    if (list->first == NULL) {
        list->first = node;
        list->last = node;
        list->first->prev = node;
        list->first->next = node;
        list->last->prev = node;
        list->last->next = node;
    } else {
        node->next = list->first;
        node->prev = list->last;
        list->first->prev = node;
        list->last->next = node;
        list->last = node;
    }

    list->size++;
}

void *collection_linked_list_get(LinkedList *list, int index) {
    if (list->size - 1 < index) {
        return 0;
    } else if (index == 0) {
        return list->first->value;
    } else if (list->size - 1 == index) {
        return list->last->value;
    } else {
        Node *current = list->first;

        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->value;
    }
}

void *collection_linked_list_remove(LinkedList *list, int index) {
    if (list->size - 1 < index) {
        return 0;
    }

    Node *node;
    void *value;

    if (index == 0) {
        // First element
        node = list->first;
        value = node->value;

        list->last->next = list->first->next;
        list->first->next->prev = list->last;
        list->first = list->first->next;
    } else if (list->size - 1 == index) {
        // Last element
        node = list->last;
        value = node->value;

        list->first->prev = list->last->prev;
        list->last->prev->next = list->first;
        list->last = list->last->prev;
    } else {
        node = list->first;

        for (int i = 0; i < index; i++) {
            node = node->next;
        }

        value = node->value;

        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    free(node);
    list->size--;
    return value;
}

bool collection_linked_list_contains(LinkedList *list, void *value) {
    if (list->first->value == value || list->last->value == value) {
        return true;
    }

    Node *node = list->first;

    for (int i = 0; i < list->size - 1; i++) {
        if (node->value == value) {
            return true;
        }

        node = node->next;
    }

    return false;
}
