#include "main.h"

char *compile(char inputData[maxLineCount][maxLineLength]) {

    // find the function definition
    int functionCodeStart = -1;  // this will store the first line that has the code that is in the function
    char functionCode[maxLineCount][maxLineLength];
    {
        int i = 0;
        while (strcmp(inputData[i], "\0")) {
            // if we've found a function definition
            if (match(inputData[i], "(function)\\s*\\{\\s*") == 1) {
                functionCodeStart = i + 1;
                printf("We found a function at line %i.\n", functionCodeStart - 1);
            }
            i++;
        }
    }

    // if there isn't a function in the code
    if (functionCodeStart == -1) {
        // skip and bypass the code to verify/add function code, as there isn't a function
        goto skipFunctionParse;
    }

    // extract the code that is within the function and put them into char functionCode[][]
    {
        int i = functionCodeStart;
        while (!match(inputData[i], "\\s*}\\s*")) {
            strcpy(functionCode[i - functionCodeStart], inputData[i]);
            strcpy(inputData[i], "---;");
            ++i;
        }
    }

    skipFunctionParse:
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
                  match(inputData[i], "(laser)\\s*;\\s*") ||
                  match(inputData[i], "(function)\\s*;\\s*") ||
                  match(inputData[i], "---;") || // means do nothing
                  // these two detect the parts of a function
                  match(inputData[i], "(function)\\s*\\{\\s*") ||
                  match(inputData[i], "\\s*}\\s*"))) {

                // set color to red
                printf("\033[31m");

                // print text
                printf("ERROR: '%s' is not defined\n", strtok(inputData[i], "\n;"));

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
        } else if (strcmp(inputData[i], "---;\n") == 0) {
            outputData[i] = '0';
        } else if (strcmp(inputData[i], "function;\n") == 0) {
            for (int j = 0; j < maxLineCount; j++) {
                if (strcmp(functionCode[j], "forward;\n") == 0) {
                    outputData[i] = 'f';
                    ++i;
                } else if (strcmp(functionCode[j], "left;\n") == 0) {
                    outputData[i] = 'l';
                    ++i;
                } else if (strcmp(functionCode[j], "right;\n") == 0) {
                    outputData[i] = 'r';
                    ++i;
                } else if (strcmp(functionCode[j], "laser;\n") == 0) {
                    outputData[i] = 'L';
                    ++i;
                } else if (strcmp(functionCode[j], "---;\n") == 0) {
                    outputData[i] = '0';
                    ++i;
                }
            }
        }
    }
    // write the compiled code to the screen

    // TODO: Write compiled instructions to file, rather than console
    printf("Instructions: %s\n", outputData);

    // run the code


    {
        return outputData;
    }
}