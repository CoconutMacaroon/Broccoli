#include "main.h"

void runtime(turtle *inputTurtle, char *instructions) {
    // TODO: read compiled code from file
    // initialize the array to blanks
    clearBoard(false);

    // and add the turtle to the board
    updateTurtleLocation(inputTurtle);

    printBoard();
    while (true) {
        // if we are done getting instructions
        if (*instructions == '\0') {
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
                // TODO: add the ability for lasers to melt ice blocks
            case 'L':
                printf("Laser fired. Bam!\n");
                switch (inputTurtle->direction) {
                    case 1:
                        printf("oh no: '%c'\n", board[inputTurtle->x - 1][inputTurtle->y - 2]);
                        if (board[inputTurtle->x - 1][inputTurtle->y - 2] == 'I') {
                            printf("we are here\n");
                            board[inputTurtle->x - 1][inputTurtle->y - 2] = 'o';
                        }
                        printBoard();
                }
                break;

            case '0':
                // '0' is a dummy instruction. It is used to zero out the outputData array in the compiler.
                // but it has to have a `case`, as it is a valid instruction
                ;
                break;

            default:
                // set color to red
                printf("\033[31m");

                // print text
                printf("ERROR: '%c' is not a valid instruction\n", *instructions);

                // and reset the color
                printf("\033[0m");

                // and quit
                exit(1);
        }
        // and move to the next instruction
        // this increments the pointer, moving it to the next char/instruction
        instructions++;
    }
}