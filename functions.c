#include "main.h"

bool doesSpotHaveNoObstacle(int x, int y) {
    if (board[x][y] != 'o') {
        if (board[x][y] != 'W') {
            if (board[x][y] != 'I') {
                return true;
            }
        }
    }
    return false;
}

void clearBoard(bool onlyClearTurtles) {
    // set each square on the board to a blank

    // for every square on the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (onlyClearTurtles == false) {
                if (doesSpotHaveNoObstacle(i, j)) {
                    board[i][j] = ' ';
                }
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
}

void initBoard() {
    // create some obstacles
    board[4][2] = 'W';
    board[0][6] = 'I';
}

void updateTurtleLocation(turtle *inputTurtle) {
    // updates the turtle on the board

    // clear all turtles from board, as we don't want multiple turtles
    clearBoard(true);

    // if it is not a puddle
    if (board[inputTurtle->x - 1][inputTurtle->y - 1] != 'o') {
        // check if we can go through it
        // and if we can't
        if (board[inputTurtle->x - 1][inputTurtle->y - 1] != ' ') {
            // print an error message

            // set color to red
            printf("\033[31m");

            // print text
            printf("ERROR: X: %i Y: %i is already occupied\n", inputTurtle->x - 1, inputTurtle->y - 1);

            // and reset the color
            printf("\033[0m");

            // and quit
            exit(1);
        }
    } else {
        // but if it is a puddle, we can go through it

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
