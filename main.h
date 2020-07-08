// include libraries
#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// define structs
typedef struct turtle {
    int x;
    int y;
    int direction;
    /*
     * 1 = up
     * 2 = right
     * 3 = down
     * 4 = left
     * */
} turtle;

// prototypes
int match(const char *string, char *pattern);
void runtime(turtle *inputTurtle, char *instructions);

// #DEFINEs
#define maxLineLength 12
#define maxLineCount 12
