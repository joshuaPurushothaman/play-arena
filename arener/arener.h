#pragma once

#include <stdlib.h>
#include <stdint.h>

typedef struct Arena {
    void* arena_start;
    void* cur_ptr;
} Arena;

/// @brief Initializes an Arena.
/// @param size `Arena` size in bytes - use `sizeof(your_type) * number_of_items`
/// @return An `Arena*` to the initialized Arena
Arena* init_arena(size_t size);

/// @brief Destructor - does nothing but `free(arena)`.
/// @param arena Pointer to the `Arena` to DESTROY
void destroy_arena(Arena* arena);

/// @brief Gets the next available chunk of memory with a given size.
/// @param arena The `Arena*` to use.
/// @param size Size in bytes of the block you're requesting - use `sizeof(your_type) * number_of_items`
/// @return A `void*` to the block you'd like to use; cast for actual usage
void* get_next(Arena* arena, size_t size);