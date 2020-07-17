#include "main.h"

void moveForward(turtle *inputTurtle) {
    printf("You try to move forward:\n");

    switch (inputTurtle->direction) {
        case 1:
            (inputTurtle->y)--;
            updateTurtleLocation(inputTurtle);
            printBoard();
            usleep(1000 * 1000);
            playSound(RobotMove);
            break;
        case 2:
            (inputTurtle->x)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
            usleep(1000 * 1000);
            playSound(RobotMove);
            break;
        case 3:
            // down
            (inputTurtle->y)++;
            updateTurtleLocation(inputTurtle);
            printBoard();
            usleep(1000 * 1000);
            playSound(RobotMove);
            break;
        case 4:
            (inputTurtle->x)--;
            updateTurtleLocation(inputTurtle);
            printBoard();
            usleep(1000 * 1000);
            playSound(RobotMove);
            break;
    }
}

void turnLeft(turtle *inputTurtle) {
    printf("You try to turn left:\n");
    (inputTurtle->direction)--;
    if (inputTurtle->direction == 0) {
        inputTurtle->direction = 4;
    }
    clearBoard(false);
    updateTurtleLocation(inputTurtle);
    printBoard();
    usleep(1000 * 1000);
    playSound(RobotMove);
}

void turnRight(turtle *inputTurtle) {
    printf("You try to turn right:\n");
    (inputTurtle->direction)++;
    if (inputTurtle->direction == 5) {
        inputTurtle->direction = 1;
    }
    clearBoard(false);
    updateTurtleLocation(inputTurtle);
    printBoard();
    usleep(1000 * 1000);
    playSound(RobotMove);
}

void fireLaser(turtle *inputTurtle) {
    printf("Attempting to fire laser:\n");
    switch (inputTurtle->direction) {
        // TODO: add ability to fire lasers in directions other than up
        case 1:
            if (board[inputTurtle->x - 1][inputTurtle->y - 2] == 'I') {
                board[inputTurtle->x - 1][inputTurtle->y - 2] = 'o';
            }
            clearBoard(false);
            updateTurtleLocation(inputTurtle);
            printBoard();
            usleep(1000 * 1000);
            break;
            // TODO: play laser sound
        default:
            fprintf(stderr, "ERROR: There is no solid ice in front of you\n");
            cleanExit(1);
    }
}
