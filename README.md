# libcollection

This is a collection framework written in C and inspired by the Java Collection
Framework. Please note: this project is just meant for learning C and the
implementation found in this library may not be suitable for production use.

## Build

`make` will build the entire project and compile a shared object in `build/bin`.

## Usage

```c
#include <stdio.h>
#include <stdlib.h>
#include "collection/collection.h"

int main(int argc, char *argv[]) {
    LinkedList *list = malloc(sizeof(LinkedList));
    collection_linked_list_append(list, (void *) 1);
    collection_linked_list_append(list, (void *) 2);
    collection_linked_list_append(list, (void *) 3);

    int64_t value = (int64_t) collection_linked_list_get(list, 2);
    printf("%ld\n", value); // 3

    int64_t valueDel = (int64_t) collection_linked_list_remove(list, 1);
    printf("%ld\n", valueDel); // 2

    bool contains = collection_linked_list_contains(list, (void *) 10);
    printf("%d\n", contains); // 0
}
```

```shell
apt install -f <libcollection>.so
gcc -L /usr/lib/collection -l collection -o <out> <in>.c
./<out>
```
