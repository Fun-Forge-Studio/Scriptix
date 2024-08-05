#include <stdio.h>
#include "scriptix/scriptix.c"

int main() {
    String value = "Hello World";

    initialize_memory_pool();

    char* a = (char*)xalloc(sizeof(value));
    printf("%p\n", a);

    return 0;
}