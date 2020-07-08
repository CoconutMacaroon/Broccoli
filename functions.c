#include "main.h"

void clearBoard(bool onlyClearTurtles) {
    // set each square on the board to a blank
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (onlyClearTurtles == false) {
                board[i][j] = ' ';
            }
            if ((onlyClearTurtles == true) && (board[i][j] == '>')) {
                board[i][j] = ' ';
            }
        }
    }
}

void updateTurtleLocation(turtle *inputTurtle) {
    // updates location of turtle
    clearBoard(true);
    board[inputTurtle->x - 1][inputTurtle->y - 1] = '>';
}

void printBoard() {
    printf("-----------------\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (j == 0) { printf("|"); }

            printf("%c|", board[j][i]);
        }
        printf("\n-----------------\n");
    }
}