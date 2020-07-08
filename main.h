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

void clearBoard(bool onlyClearTurtles);

void printBoard();

void runtime(turtle *inputTurtle, char *instructions);

void updateTurtleLocation(turtle *inputTurtle);

// #DEFINEs
#define maxLineLength 12
#define maxLineCount 12
#define turtleStartX 4
#define turtleStartY 4

// globals
char board[8][8];
