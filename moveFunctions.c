#include "main.h"

void moveForward(turtle *inputTurtle) {
    printf("You moved forward\n");
    if (inputTurtle->x == 8) {
        // set color to red
        printf("\033[31m");

        // print text
        printf("ERROR: You have reached the end of the board. You can't move forward.");

        // and reset the color
        printf("\033[0m");

        // and quit
        exit(1);
    }

    switch (inputTurtle->direction) {
        case 1:
            (inputTurtle->y)--;
            updateTurtleLocation(inputTurtle);
            printBoard();
        case 2:
            (inputTurtle->x)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
        case 3:
            // down
            (inputTurtle->y)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
        case 4:
            (inputTurtle->x)--;
            updateTurtleLocation(inputTurtle);
            printBoard();
    }
}