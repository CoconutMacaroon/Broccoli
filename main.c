#include "main.h"

int main() {
    char inputData[maxLineCount][maxLineLength];
    /*
     * f = forward
     * l = left
     * r = right
     * L = laser
     * 0 = <none>    the runtime should ignore characters that are zeros
     * */
    strcpy(inputData[0], "laser;\n");
    strcpy(inputData[1], "left;\n");
    strcpy(inputData[2], "right;\n");
    strcpy(inputData[3], "forward;\n");
    strcpy(inputData[4], "right;\n");
    strcpy(inputData[5], "forward;\n");
    strcpy(inputData[6], "\0");

    // validate the code
    {
        int i = 0;
        while (true) {
            // if we have reached the final statement
            if (strcmp(inputData[i], "\0") == 0) {
                break;
            }
            // if the code doesn't match a valid statement
            if (!(match(inputData[i], "(forward)\\s*;\\s*") ||
                  match(inputData[i], "(left)\\s*;\\s*") ||
                  match(inputData[i], "(right)\\s*;\\s*") ||
                  match(inputData[i], "(laser)\\s*;\\s*"))) {

                // set color to red
                printf("\033[31m");

                // print text
                printf("ERROR: '%s' is not defined", strtok(inputData[i], "\n;"));

                // and reset the color
                printf("\033[0m");

                // and quit
                exit(1);
            }
            ++i;
        }
    }

    //
    //  compile the code
    //

    // create a variable to store the compiled code
    char outputData[maxLineLength];

    for (int i = 0; i < maxLineCount; i++) {
        outputData[i] = '0';
    }

    for (int i = 0; i < maxLineCount; i++) {

        if (strcmp(inputData[i], "forward;\n") == 0) {
            outputData[i] = 'f';
        } else if (strcmp(inputData[i], "left;\n") == 0) {
            outputData[i] = 'l';
        } else if (strcmp(inputData[i], "right;\n") == 0) {
            outputData[i] = 'r';
        } else if (strcmp(inputData[i], "laser;\n") == 0) {
            outputData[i] = 'L';
        }

    }
    // write the compiled code to the screen
    printf("Instructions: %s\n", outputData);

    //
    //  run the code
    //

    {
        turtle myTurtle;
        myTurtle.x = turtleStartX;
        myTurtle.y = turtleStartY;
        myTurtle.direction = 1;
        runtime(&myTurtle, &outputData[0]);
    }
    return 0;
}


/*
 * f = forward
 * l = left
 * r = right
 * L = laser
 * 0 = <none>    the runtime should ignore characters that are zeros
 * */
