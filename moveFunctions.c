#include "main.h"

void moveForward(turtle *inputTurtle) {
    printf("You try to move forward\n");

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