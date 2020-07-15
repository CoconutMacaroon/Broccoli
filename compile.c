#include "main.h"

char *compile(char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH]) {
    int startOfFunction = -1;
    char functionCode[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    // initialize the array
    {
        for (int i = 0; i < MAX_LINE_COUNT; i++) {
            for (int j = 0; j < MAX_LINE_LENGTH; j++) {
                functionCode[i][j] = '0';
            }
        }
        for (int i = 0; i < MAX_LINE_COUNT; i++) {
            strcpy(functionCode[i], "---;\n");
        }
    }

    {
        int i = 0;
        while (strcmp(inputData[i], "\0")) {
            // if we've found a function definition
            startOfFunction = (match(inputData[i], "(function)\\s*\\{\\s*") == 1) ? i + 1 : startOfFunction;
            i++;
        }
    }

    // if a function was detected
    if (!(startOfFunction == -1)) {
        int i = startOfFunction;
        while (!match(inputData[i], "\\s*}\\s*")) {
            strcpy(functionCode[i - startOfFunction], inputData[i]);
            strcpy(inputData[i], "---;");
            ++i;
        }
    }

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
                fprintf(stderr, "ERROR: '%s' is not defined\n", strtok(inputData[i], "\n;"));
                playSound(error);
                exit(1);
            }
            ++i;
        }
    }

    for (int i = 0; i < MAX_LINE_COUNT; i++) {
        outputData[i] = '0';
    }
    int outputDataIndex = 0;
    for (int i = 0; i < MAX_LINE_COUNT; i++) {

        if (strcmp(inputData[i], "forward;\n") == 0) {
            outputData[outputDataIndex] = 'f';
            ++outputDataIndex;
        } else if (strcmp(inputData[i], "left;\n") == 0) {
            outputData[outputDataIndex] = 'l';
            ++outputDataIndex;
        } else if (strcmp(inputData[i], "right;\n") == 0) {
            outputData[outputDataIndex] = 'r';
            ++outputDataIndex;
        } else if (strcmp(inputData[i], "laser;\n") == 0) {
            outputData[outputDataIndex] = 'L';
            ++outputDataIndex;
        } else if (strcmp(inputData[i], "---;\n") == 0) {
            ;
        } else if (strcmp(inputData[i], "function;\n") == 0) {
            for (int j = 0; j < MAX_LINE_COUNT; j++) {
                if (strcmp(functionCode[j], "forward;\n") == 0) {
                    outputData[outputDataIndex] = 'f';
                    ++outputDataIndex;
                } else if (strcmp(functionCode[j], "left;\n") == 0) {
                    outputData[outputDataIndex] = 'l';
                    ++outputDataIndex;
                } else if (strcmp(functionCode[j], "right;\n") == 0) {
                    outputData[outputDataIndex] = 'r';
                    ++outputDataIndex;
                } else if (strcmp(functionCode[j], "laser;\n") == 0) {
                    outputData[outputDataIndex] = 'L';
                    ++outputDataIndex;
                } else if (strcmp(functionCode[j], "---;\n") == 0) {
                    ;
                } else {
                    fprintf(stderr, "ERROR: Unknown command '%s'\n", strtok(functionCode[j], "\n"));
                    playSound(error);
                    exit(1);
                }
            }
        }
    }
    return outputData;
}
