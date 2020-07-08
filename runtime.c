#include "main.h"

void runtime(turtle *inputTurtle, char *instructions) {
    // initialize the array to blanks
    clearBoard(false);

    // and add the turtle to the board
    updateTurtleLocation(inputTurtle);

    while (true) {
        // if we are done getting instructions
        if (*instructions == '\0') {
            break;
        }

        // now for actually dealing with each instruction
        switch (*instructions) {
            case 'f':
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

                // move in the correct direction based on inputTurtle-> direction
                if (inputTurtle->direction == 1) {
                    // up
                    (inputTurtle->y)--;
                    updateTurtleLocation(inputTurtle);
                    printBoard();
                } else if (inputTurtle->direction == 2) {
                    (inputTurtle->x)++;
                    updateTurtleLocation(inputTurtle);
                    printBoard();
                } else if (inputTurtle->direction == 3) {
                    // down
                    (inputTurtle->y)++;
                    updateTurtleLocation(inputTurtle);
                    printBoard();
                } else if (inputTurtle->direction == 4) {
                    (inputTurtle->x)--;
                    updateTurtleLocation(inputTurtle);
                    printBoard();
                }
                break;

            case 'l':
                /*
                 * 1 = up
                 * 2 = right
                 * 3 = down
                 * 4 = left
                 * */
                printf("You turned left\n");
                if (inputTurtle->direction == 1) {
                    inputTurtle->direction = 4;
                } else {
                    (inputTurtle->direction)--;
                }
                updateTurtleLocation(inputTurtle);
                printBoard();
                break;

            case 'r':
                printf("You turned right\n");
                (inputTurtle->direction)++;
                if (inputTurtle->direction == 5) {
                    inputTurtle->direction = 1;
                }
                updateTurtleLocation(inputTurtle);
                printBoard();
                break;

            case 'L':
                printf("Laser fired. Bam!\n");
                break;

            case '0':
                // '0' is a dummy instruction. It is used to zero out the outputData array in the compiler.
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
        instructions++;
    }
}