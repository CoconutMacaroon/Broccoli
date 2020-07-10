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

    (inputTurtle->direction)--;
    if (inputTurtle->direction == 0) {
        inputTurtle->direction = 4;
    }

    clearBoard(false);
    updateTurtleLocation(inputTurtle);
    printBoard();
}

void turnRight(turtle *inputTurtle) {
    printf("You try to turn right\n");
    (inputTurtle->direction)++;
    if (inputTurtle->direction == 5) {
        inputTurtle->direction = 1;
    }

    clearBoard(false);
    updateTurtleLocation(inputTurtle);
    printBoard();
}

void fireLaser(turtle *inputTurtle) {
    // TODO: The melted ice gets cleared after one frame
    printf("Attempting to file laser\n");
    switch (inputTurtle->direction) {
        case 1:
            if (board[inputTurtle->x - 1][inputTurtle->y - 2] == 'I') {
                printf("we are here\n");
                board[inputTurtle->x - 1][inputTurtle->y - 2] = 'o';
            }
            clearBoard(false);
            updateTurtleLocation(inputTurtle);
            printBoard();
            break;
        default:
            // set color to red
            printf("\033[31m");

            // print text
            printf("ERROR: There is no solid ice in front of you\n");

            // and reset the color
            printf("\033[0m");

            // and quit
            exit(1);
    }
}
