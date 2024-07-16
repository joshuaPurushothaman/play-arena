// Sample: A Vector that uses an arena!
#include "arener/arener.h"

// Awkward generic-ish thing going on here LOL
#ifndef T
#define T int
#endif

typedef struct Vector {
    // IF for testing purposes you use malloc() and free(),
    // ... make sure to free the vector! Duh ;)
    void* (*alloc_fx_ptr) (size_t);
    int length;
    int capacity;
    T* items;
} Vector;

/// @brief Initializes a `Vector`.
/// @param default_capacity
/// @param alloc_function_ptr Pass in `malloc` OR an `Arena` `get_next` ;)
/// @return the initialized `Vector*`
Vector* init_vector(int default_capacity, void* (*alloc_fx_ptr) (size_t));
// With an Arena, you wouldn't destroy a vector!
// void destroy_vector(Vector* vec); // and send him to the moon!

void add_item(Vector* vec, T item);
T get(Vector* vec, int i);