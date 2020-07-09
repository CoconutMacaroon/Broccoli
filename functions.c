#include "main.h"

void clearBoard(bool onlyClearTurtles) {
    // set each square on the board to a blank

    // for every square on the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (onlyClearTurtles == false) {
                board[i][j] = ' ';
            }
            // if we want to only clear turtles
            if (onlyClearTurtles == true) {
                // if it is a turtle
                if ((board[i][j] == '>') || (board[i][j] == '<') || (board[i][j] == 'v') || (board[i][j] == '^')) {
                    // wipe it out
                    board[i][j] = ' ';
                }
            }
        }
    }

    // create some obstacles
    board[1][1] = 'e';
}

void updateTurtleLocation(turtle *inputTurtle) {
    // updates the turtle on the board

    // clear all turtles from board, as we don't want multiple turtles
    clearBoard(true);

    // based on the turtle's direction, place the appropriate icon on the board
    switch (inputTurtle->direction) {
        case 1:
            board[inputTurtle->x - 1][inputTurtle->y - 1] = '^';
            break;
        case 2:
            board[inputTurtle->x - 1][inputTurtle->y - 1] = '>';
            break;
        case 3:
            board[inputTurtle->x - 1][inputTurtle->y - 1] = 'v';
            break;
        case 4:
            board[inputTurtle->x - 1][inputTurtle->y - 1] = '<';
            break;
    }
}

void printBoard() {
    // print the board
    printf("-----------------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0) { printf("|"); }

            printf("%c|", board[j][i]);
        }
        printf("\n-----------------\n");
    }
}

int match(const char *string, char *pattern) {
    // full credit goes to https://stackoverflow.com/a/1631458. code style slightly modified.
    int status;
    regex_t re;

    if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
        return (0);      /* Report error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return (0);      /* Report error. */
    }
    return (1);
}