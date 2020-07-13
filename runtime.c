#include "main.h"

void runtime(turtle *inputTurtle, char *instructions) {
    // TODO: Read compiled code from file
    // initialize the array to blanks
    clearBoard(false);

    // and add the turtle to the board
    updateTurtleLocation(inputTurtle);

    // and add the walls, ice, etc.
    initBoard();

    // and display the starting board
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

            default:
                // complain about invalid instruction
                fprintf(stderr, "ERROR: '%c' is not a valid instruction\n", *instructions);

                // and quit
                exit(1);
        }
        // and move to the next instruction
        // this increments the pointer, moving it to the next char/instruction
        instructions++;
    }
}