// include libraries
#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// define structs
typedef struct turtle {
    // these start counting at ONE
    int x;
    int y;
    int direction;
} turtle;

// prototypes
int compile();

int match(const char *string, char *pattern);

void clearBoard(bool onlyClearTurtles);

void printBoard();

void initBoard();

void runtime(turtle *inputTurtle, char *instructions);

void updateTurtleLocation(turtle *inputTurtle);

void moveForward(turtle *inputTurtle);

void turnLeft(turtle *inputTurtle);

void turnRight(turtle *inputTurtle);

void fireLaser(turtle *inputTurtle);

// #DEFINEs
#define maxLineLength 12
#define maxLineCount 12
#define turtleStartX 1
#define turtleStartY 8

// globals
char board[8][8];
