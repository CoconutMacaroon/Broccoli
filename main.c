#include "main.h"

int main(int argc, char *argv[]) {
    char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH];
    bool doCompile = false;
    bool doRun = false;
    bool doHelp = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-c") == 0) {
            doCompile = true;
        }
        if (strcmp(argv[i], "-r") == 0) {
            doRun = true;
        }
        if (strcmp(argv[i], "-?") == 0) {
            doHelp = true;
        }
    }

    // if no arguments are passed
    if (!doCompile && !doRun && !doHelp) {
        puts("ERROR: You forgot arguments. Run with -? for valid options.");
        exit(1);
    }
    if (doHelp == true) {
        puts("broc: broc [-c] [-r] [-?]\nCompile/run Broccoli code. Reads code from main.broc and reads compiled code from main.brocc.\n\nOptions:\n-c\tCompile code\n-r\tRun code\n-?\tDisplay help and exit\n");
        exit(0);
    }
    if (doCompile == true) {
        // get the un-compiled input code
        FILE *inputFileH = fopen("main.broc", "r");
        for (int i = 0; i < MAX_LINE_COUNT; i++) {
            if (fgets(inputData[i], MAX_LINE_LENGTH, inputFileH) == NULL) {
                break;
            }
        }
        fclose(inputFileH);

        // compile the code
        {
            FILE *outputFileH = fopen("main.brocc", "w");
            char compiledCode[MAX_LINE_COUNT];
            strcpy(compiledCode, compile(inputData));
            int i = 0;
            // can the i++ go inside of the indexing of compiledCode
            while (compiledCode[i] != '0') {
                fputc(compiledCode[i++], outputFileH);
            }
            fclose(outputFileH);
        }
    }
    if (doRun == true) {
        // read the compiled code into memory
        FILE *compiledCodeH = fopen("main.brocc", "r");
        char *compiledCode = malloc(MAX_LINE_LENGTH * sizeof(char));
        if (fgets(compiledCode, MAX_LINE_LENGTH, compiledCodeH) == NULL) {
            fprintf(stderr, "ERROR: A problem occurred during file IO. Was the compiled code missing or deleted?");
            exit(2);
        }
        fclose(compiledCodeH);


        // create a turtle
        turtle myTurtle;
        myTurtle.x = TURTLE_START_X;
        myTurtle.y = TURTLE_START_Y;
        myTurtle.direction = 1;

        // run the compiled code
        return runtime(&myTurtle, compiledCode);
    }
}
