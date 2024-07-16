#include "vector_t.h"

Vector* init_vector(int default_capacity, void* (*alloc_fx_ptr) (size_t)) {
    Vector* v = (Vector*)alloc_fx_ptr(default_capacity);

    v->alloc_fx_ptr = alloc_fx_ptr;
    v->capacity = default_capacity;
    v->length = 0;
    v->items = (T*)alloc_fx_ptr(sizeof(T) * default_capacity);

    return v;
}

void add_item(Vector* v, T item) {
    if (v->length >= v->capacity) {
        // obviously, cap * 2 or something would perform better... testing!
        int new_size = v->capacity + 1;

        T* new_array = v->alloc_fx_ptr(sizeof(T) * new_size);
        memcpy();
    }

    v->items[v->length] = item;
    v->length++;
}

T get(Vector* vec, int i) {
    return i < vec->length ? vec->items[i] : NULL;
}