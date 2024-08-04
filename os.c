#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "include/gdt.h"
#include "include/console.h"
#include "src/gdt.c"
#include "src/console.c"

int main()
{
    clear_screen();
    setcolor(WHITE_COLOR, BLACK_COLOR);
    TypeLine("Welcome to my operating system!");
    GlobalDescriptorTable table;
    initTable(&table);

    while(1) {}
    return 0;
}