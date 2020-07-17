// include libraries
#include <string.h>
#include <regex.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

// define structs
typedef struct turtle {
    // these start counting at ONE
    int x;
    int y;
    int direction;
} turtle;

// #DEFINEs
#define MAX_LINE_LENGTH 1000
#define MAX_LINE_COUNT 1000
#define TURTLE_START_X 1
#define TURTLE_START_Y 8

// enumerations
enum soundEffect {
    Error, RobotMove
};

// prototypes
void cleanExit(int exitCode);

void clearConsole();

void winEffect();

char *compile(char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH]);

int match(const char *string, char *pattern);

int runtime(turtle *inputTurtle, char *instructions);

void clearBoard(bool onlyClearTurtles);

void initBoard();

void printBoard();

void updateTurtleLocation(turtle *inputTurtle);

void moveForward(turtle *inputTurtle);

void turnLeft(turtle *inputTurtle);

void turnRight(turtle *inputTurtle);

void fireLaser(turtle *inputTurtle);

void playSound(enum soundEffect effect);

void init();

// globals
char board[8][8];
char outputData[MAX_LINE_LENGTH];

bool playSounds;
bool doCompile;
bool doRun;
bool doHelp;
bool nonInteractive;