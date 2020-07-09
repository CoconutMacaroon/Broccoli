#include "main.h"

void moveForward(turtle *inputTurtle) {
    printf("You try to move forward\n");
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
            break;
        case 2:
            (inputTurtle->x)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
            break;
        case 3:
            // down
            (inputTurtle->y)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
            break;
        case 4:
            (inputTurtle->x)--;
            updateTurtleLocation(inputTurtle);
            printBoard();
            break;
    }
}

void turnLeft(turtle *inputTurtle) {
    printf("You try to turn left\n");
    if (inputTurtle->direction == 1) {
        inputTurtle->direction = 4;
    } else {
        (inputTurtle->direction)--;
    }
    updateTurtleLocation(inputTurtle);
    printBoard();
}

void turnRight(turtle *inputTurtle) {
    printf("You try to turn right\n");
    (inputTurtle->direction)++;
    if (inputTurtle->direction == 5) {
        inputTurtle->direction = 1;
    }
    updateTurtleLocation(inputTurtle);
    printBoard();
}