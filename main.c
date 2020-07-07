#include "main.h"

int main() {
    char inputData[maxLineCount][maxLineLength];

    /*
     * f = forward
     * l = left
     * r = right
     * L = laser
     * */
    strcpy(inputData[0], "laaser;\n");
    strcpy(inputData[1], "forward;\n");
    strcpy(inputData[2], "\0");

    // validate the code
    {
        int i = 0;
        while (true) {
            if (strcmp(inputData[i], "\0") == 0) {
                break;
            }
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

    // compile the code

    char outputData[maxLineLength];

    for (int i = 0; i < maxLineCount; i++) {
        outputData[i] = '0';
    }
    // write the compiled code to the screen
    puts(outputData);
    return 0;
}

int match(const char *string, char *pattern) {
    // full credit goes to https://stackoverflow.com/a/1631458. code style slightly modified.
    int status;
    regex_t re;

    if (regcomp(&re, pattern, REG_EXTENDED | REG_NOSUB) != 0) {
        return (0);      /* Report error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    if (status != 0) {
        return (0);      /* Report error. */
    }
    return (1);
}

