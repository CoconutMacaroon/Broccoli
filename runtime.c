#include "main.h"

int runtime(turtle *inputTurtle, char *instructions) {
    clearBoard(false);
    updateTurtleLocation(inputTurtle);
    initBoard();
    printf("Starting board:\n");
    printBoard();

    // until we are done
    while (true) {
        // if we are done getting instructions
        if (instructions == NULL) {
            break;
        }

        switch (*instructions) {
            case 'f':
                // forward
                moveForward(inputTurtle);
                break;

            case 'l':
                // left
                turnLeft(inputTurtle);
                break;

            case 'r':
                // right
                turnRight(inputTurtle);
                break;

                // laser
            case 'L':
                fireLaser(inputTurtle);
                break;

            case '0':
                // '0' is a dummy instruction. It is used to zero out the outputData array in the compiler.
                // but it has to have a `case`, as it is a valid instruction
                ;
                break;
            case '\0':
                // '\0' is the end of the program/instructions. It signifies the end of the instructions
                return 0;
            default:
                fprintf(stderr, "ERROR: '%i' is not a valid instruction\n", *instructions);
                playSound(error);
                cleanExit(1);
        }
        // and move to the next instruction
        // this increments the pointer, moving it to the next char/instruction
        instructions++;
    }
    return 1;
}