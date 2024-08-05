#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024 // Size of the memory pool

char memory_pool[POOL_SIZE]; // The memory pool

typedef struct Block
{
    size_t size;
    struct Block *next;
    int free;
} Block;

#define BLOCK_SIZE sizeof(Block)

Block *free_list = (void *)memory_pool; // Start of the free list

void initialize_memory_pool() {
    free_list->size = POOL_SIZE - BLOCK_SIZE;
    free_list->next = NULL;
    free_list->free = 1;
}

/** @brief Manages the use of memory */
void *xalloc(size_t size) {
    Block *current = free_list;
    while (current != NULL)
    {
        if (current->free && current->size >= size)
        {
            if (current->size > size + BLOCK_SIZE)
            {
                // Split the block
                Block *new_block = (void *)((char *)current + BLOCK_SIZE + size);
                new_block->size = current->size - size - BLOCK_SIZE;
                new_block->next = current->next;
                new_block->free = 1;

                current->size = size;
                current->next = new_block;
            }
            current->free = 0;
            return (void *)((char *)current + BLOCK_SIZE);
        }
        current = current->next;
    }
    return NULL;
}

/** @brief Free a block allocated by `xalloc`. */
void xfree(void *ptr) {
    if (!ptr)
        return;

    Block *block_ptr = (Block *)((char *)ptr - BLOCK_SIZE);
    block_ptr->free = 1;

    // Merge contiguous free blocks
    Block *current = free_list;
    while (current != NULL)
    {
        if (current->free && current->next && current->next->free)
        {
            current->size += current->next->size + BLOCK_SIZE;
            current->next = current->next->next;
        }
        current = current->next;
    }
}