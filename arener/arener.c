#include "arener.h"

#include <stdio.h> // TODO: consider writing to a debug file instead

#define CYAN "\x1b[36m"
#define DEFAULT "\x1b[39m"

Arena* init_arena(size_t size) {
    Arena* ret = (Arena*)malloc(sizeof(Arena));

    if (ret == NULL) {
        fprintf(stderr, CYAN"mem fail trying to make an Arena :("DEFAULT);
        return NULL;
    }

    void* new_block = malloc(size);

    if (new_block == NULL) {
        fprintf(stderr, CYAN"mem fail trying to make a new_block :("DEFAULT);
        return NULL;
    }

    ret->arena_start = new_block;
    ret->cur_ptr = ret->arena_start;

    printf(CYAN"Arena initialized at address %p with size %lu.\n"DEFAULT, ret->arena_start, size);

    return ret;
}

void destroy_arena(Arena* arena) {
    printf(CYAN"Arena freed at address %p.\n"DEFAULT, arena->arena_start);
    free(arena);
}

void* get_next(Arena* arena, size_t size) {
    printf(CYAN"New block of size %lu requested for arena at address %p.\n", size, arena->arena_start);

    uint8_t* casted_ptr = ((uint8_t*)(arena->cur_ptr));

    printf("\tOld address: %p\n\tNew address: %p\n"DEFAULT, casted_ptr, casted_ptr + size);

    casted_ptr += size;
    arena->cur_ptr = casted_ptr;

    return arena->cur_ptr;
}

#undef CYAN
#undef DEFAULT