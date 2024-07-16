#include <stdio.h>

#include "arener/arener.h"
#include "vector_t.h"

// Demo: Parse a CSV at runtime!

typedef struct Data
{
    // ID,Title,Author,Genre,Price,Rating,Stock
    // 1,The Silent Patient,Alex Michaelides,Thriller,12.99,4.5,34
    int id;
    char *title;
    char *author;
    char *genre;
    float price;
    float rating;
    int stock;
} Data;

// and for reference, my "diy classes" in C is just

// ```c
// typedef struct Drivetrain {
//   // fields...
// } Drivetrain;

// void create_drivetrain(Drivetrain* dt, [ctor args here]);
// void move_around(Drivetrain* dt, [args here]);

// // Usage:
// int main() {
//   Drivetrain dt

// }
// ```

// so you have to pass a drivetrain address  `&dt` everywhere you go bascially

int main()
{
    Arena *arena = init_arena(64000);

    // FILE* csv = fopen("dater.csv", "r");
    // if (csv == NULL) { printf("dater.csv not found\n"); return -1; }

    // const int max_line_len = 256;
    // char cur_line[max_line_len];

    // while (fgets(cur_line, max_line_len, csv)) {
    //     printf("%s", cur_line);
    //     parse(cur_line);
    // }

    // fclose(csv);
    destroy_arena(arena);
    return 0;
}