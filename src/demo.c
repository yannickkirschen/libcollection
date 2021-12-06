#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "collection.h"

int main() {
    LinkedList *list = malloc(sizeof(LinkedList));
    collection_linked_list_append(list, (void *) 1);
    collection_linked_list_append(list, (void *) 2);
    collection_linked_list_append(list, (void *) 3);

    int64_t value = (int64_t) collection_linked_list_get(list, 2);
    printf("%lld\n", value); // 3

    int64_t valueDel = (int64_t) collection_linked_list_remove(list, 1);
    printf("%lld\n", valueDel); // 2

    bool contains = collection_linked_list_contains(list, (void *) 10);
    printf("%d\n", contains); // 0
}
