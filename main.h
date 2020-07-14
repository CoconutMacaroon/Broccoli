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

// #DEFINEs
#define MAX_LINE_LENGTH 15
#define MAX_LINE_COUNT 15
#define TURTLE_START_X 1
#define TURTLE_START_Y 8

// this is to know if we are debugging
#define DEBUG

// prototypes
char *compile(char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH]);

int match(const char *string, char *pattern);

void clearBoard(bool onlyClearTurtles);

void printBoard();

void initBoard();

int runtime(turtle *inputTurtle, char *instructions);

void updateTurtleLocation(turtle *inputTurtle);

void moveForward(turtle *inputTurtle);

void turnLeft(turtle *inputTurtle);

void turnRight(turtle *inputTurtle);

void fireLaser(turtle *inputTurtle);

// globals
char board[8][8];
char outputData[MAX_LINE_LENGTH];
