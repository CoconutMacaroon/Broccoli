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
void clearConsole() {
    // this clears the CONSOLE, not the board
    if (nonInteractive == true) {
        return;
    }
    system("clear");
}

void winEffect() {
    clearConsole();
    int sleepTimeMilliseconds = 500;
    // thanks to https://ascii.co.uk/art/jewels for the win ASCII art
    for(int i = 0; i < 8; ++i) {
        usleep(sleepTimeMilliseconds * 1000);
        printf("%s", "You win!\n");
        printf("%s", "  _______\n"
                     ".'_/_|_\\_'.\n"
                     "\\`\\  |  /`/\n"
                     " `\\\\ | //'\n"
                     "   `\\|/`\n"
                     "     `\n");
        usleep(sleepTimeMilliseconds * 1000);
        clearConsole();
    }
    cleanExit(0);
}

void updateTurtleLocation(turtle *inputTurtle) {
    // updates the turtle on the board

    // clear all turtles from board, as we don't want multiple turtles
    clearBoard(true);
    if(board[inputTurtle->x - 1][inputTurtle->y - 1] == '@') {
        winEffect();
    }
    // if it is not a puddle
    if (board[inputTurtle->x - 1][inputTurtle->y - 1] == 'o') {
        goto here;
    }

    // check if we can go through it
    if (board[inputTurtle->x - 1][inputTurtle->y - 1] != ' ') {
        // and if we can't
        fprintf(stderr, "ERROR: X: %i Y: %i is already occupied\n", inputTurtle->x - 1, inputTurtle->y - 1);
        playSound(Error);
        cleanExit(1);
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
    // clear the screen
    clearConsole();
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
        return (0);      /* Report Error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return (0);      /* Report Error. */
    }
    return (1);
}

void playSound(enum soundEffect effect) {
    if (playSounds == false) {
        printf("%s\n", "INFO: Playing sounds is disabled");
        return;
    }

    switch (effect) {
        case Error:
            system("mpv Error.wav > /dev/null 2>&1 &");
            break;
        case RobotMove:
            system("mpv move.wav > /dev/null 2>&1 &");
            break;
    }
}

void cleanExit(int exitCode) {
    // unhide the cursor
    printf("\e[?25h");
    exit(exitCode);
}

void initVariables() {
    // this sets up the variables that are declared in main.h
    playSounds = true;
    doCompile = false;
    doRun = false;
    doHelp = false;
    nonInteractive = false;
}