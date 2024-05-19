#include <stdio.h>

#include "arener/arener.h"

int main() {

    
    Arena* arena = init_arena(128 * sizeof(int));

    int count = 5;
    int* vec = get_next(arena, sizeof(int) * count);
    // int* vec = get_next(arena, 20);
    // int vec[] = { 4, 5, 6, 7, 6 };

    for (int i = 0; i < 5; i++)
    {
        printf("%i, %i\n", i, vec[i]);
    }

    // getchar();   //  hit enter to continue

    // char c;
    // do {
    //     printf("Enter another item, or n to quit: ");
    //     // c = getchar();

    //     // int newitem = atoi(c);
    //     // vec... temp LOL
    //     // for (int i = 0; i < 5; i++)
    //     // {
    //     //     printf("%i, %i\n", i, vec[i]);

    //     // }
    //     // printf("%i", newitem);
    // } while (c != 'n');

    destroy_arena(arena);
    return 0;
}