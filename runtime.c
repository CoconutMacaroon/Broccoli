#include "main.h"

int runtime(turtle *inputTurtle, char *instructions) {
    // TODO: Read compiled code from file
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

        // now for actually dealing with each instruction
        switch (*instructions) {
            // if we are moving forward
            case 'f':
                moveForward(inputTurtle);
                break;

                // if we are moving left
            case 'l':
                turnLeft(inputTurtle);
                break;

                // if we are moving right
            case 'r':
                turnRight(inputTurtle);
                break;

                // if we are firing the turtle's laser
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
                // complain about invalid instruction
                // for some reason, it is a null char
                fprintf(stderr, "ERROR: '%i' is not a valid instruction\n", *instructions);

                // and quit
                exit(1);
        }
        // and move to the next instruction
        // this increments the pointer, moving it to the next char/instruction
        instructions++;
    }
    return 1;
}