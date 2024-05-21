#include "arener.h"

/// #define DEBUG_ARENA enables debug printing
#define DEBUG_ARENA // TODO: wth lol
#ifdef DEBUG_ARENA
#include <stdio.h> // TODO: consider writing to a debug file instead
#endif

Arena* init_arena(size_t size)
{
    Arena* ret = (Arena*)malloc(sizeof(Arena));

    if (ret == NULL) {
// #ifdef DEBUG_ARENA
        printf("mem fail trying to make an Arena :(");
// #endif
        return NULL;
    }

    void* new_block = malloc(size);

    if (new_block == NULL) {
// #ifdef DEBUG_ARENA
        printf("mem fail trying to make a new_block :(");
// #endif
        return NULL;
    }

    ret->arena_start = new_block;
    ret->cur_ptr = ret->arena_start;

#ifdef DEBUG_ARENA
    printf("Arena initialized at address %p with size %lu\n", ret->arena_start, size);
#endif

    return ret;
}

void destroy_arena(Arena* arena)
{
#ifdef DEBUG_ARENA
    printf("Arena freed at address %p\n", arena->arena_start);
#endif

    free(arena);
}

void* get_next(Arena* arena, size_t size)
{
#ifdef DEBUG_ARENA
    printf("New block of size %lu requested for arena at address %p; ", size, arena->arena_start);
#endif

    // ((uint8_t*)(arena->cur_ptr)) += size; // uh, gcc throws error... yikes-y solution! ha ha.
    uint8_t* casted_ptr = ((uint8_t*)(arena->cur_ptr));

#ifdef DEBUG_ARENA
    printf("Old address %p; New address %p\n", casted_ptr, casted_ptr + size);
#endif

    casted_ptr += size;


    arena->cur_ptr = casted_ptr;

    return arena->cur_ptr;
}
