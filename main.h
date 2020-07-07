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
} turtle;

// prototypes
int match(const char *string, char *pattern);

void plotGrid(turtle *inputTurtle);

// #DEFINEs
#define maxLineLength 12
#define maxLineCount 12