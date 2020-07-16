#include "main.h"

bool doesSpotHaveNoObstacle(int x, int y) {
    if (board[x][y] != 'o') {
        if (board[x][y] != 'W') {
            if (board[x][y] != 'I') {
                if (board[x][y] != '@') {
                    return true;
                }
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
    board[3][3] = '@';
}

void updateTurtleLocation(turtle *inputTurtle) {
    // updates the turtle on the board

    // clear all turtles from board, as we don't want multiple turtles
    clearBoard(true);
    if(board[inputTurtle->x - 1][inputTurtle->y - 1] == '@') {
        printf("%s", "You win!\n");
        exit(0);
    }
    // if it is not a puddle
    if (board[inputTurtle->x - 1][inputTurtle->y - 1] == 'o') {
        goto here;
    }

    // check if we can go through it
    if (board[inputTurtle->x - 1][inputTurtle->y - 1] != ' ') {
        // and if we can't
        fprintf(stderr, "ERROR: X: %i Y: %i is already occupied\n", inputTurtle->x - 1, inputTurtle->y - 1);
        playSound(error);
        exit(1);
    }
    here:
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
    printf("\n");
}

int match(const char *string, char *pattern) {
    // full credit goes to https://stackoverflow.com/a/1631458. Code style slightly modified.
    /*
     * Match string against the extended regular expression in
     * pattern, treating errors as no match.
     *
     * Return 1 for match, 0 for no match.
     */
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

void playSound(enum soundEffect effect) {
    switch (effect) {
        case error:
            system("mpv error.wav > /dev/null 2>&1");
            break;
        case roboMove:
            system("mpv move.wav > /dev/null 2>&1");
            break;

    }
}