#include <stdio.h>

#include "arener/arener.h"


int main() {
    Arena* arena = init_arena(65536);

    int count = 5;
    int* vec = get_next(arena, sizeof(int) * count);

    for (int i = 0; i < count; i++)
    {
        printf("aa%i, %i\n", i, vec[i]);
    }

    getchar();   //  hit enter to continue
    destroy_arena(arena);
    return 0;
}