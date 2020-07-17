#include "main.h"

int main(int argc, char *argv[]) {
    init();
    // this command would unhide it: printf("\e[?25h");
    char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    // deal with command line arguments
    char filename[256] = "";
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-c") == 0) {
            doCompile = true;
        }
        if (strcmp(argv[i], "-s") == 0) {
            playSounds = false;
        }
        if (strcmp(argv[i], "-r") == 0) {
            doRun = true;
        }
        if (strcmp(argv[i], "-?") == 0) {
            doHelp = true;
        }
        if (strcmp(argv[i], "-n") == 0) {
            nonInteractive = true;
        }
        if (strcmp(argv[i], "-f") == 0) {
            ++i;
            if (!(i < argc)) {
                printf("Hey! You need a filename after -f\n");
                cleanExit(1);
            }
            strcpy(filename, argv[i]);
        }
    }
    if (strcmp(filename, "") == 0) {
        printf("Hey! The -f argument is required!\n");
        cleanExit(1);
    }

    // if no arguments are passed
    if (!doCompile && !doRun && !doHelp) {
        printf("WARN: You didn't instruct broc to do anything. Run it with -? for options.\n");
    }
    if (doHelp == true) {
        puts("broc: broc [-c] [-r] [-?]\nCompile/run Broccoli code. Reads code from the parameter from the -f argument. Reads compiled code from main.brocc.\n\nOptions:\n-c\tCompile code\n-s\tDon't play sounds\n-r\tRun code\n-?\tDisplay help and exit\n-n\tRun the code in noninteractive mode\n");
        cleanExit(0);
    }
    if (doCompile == true) {
        // get the un-compiled input code
        FILE *inputFileH = fopen(filename, "r");
        if (inputFileH == NULL) {
            printf("ERROR: Couldn't read file '%s'.\n", filename);
            cleanExit(1);
        }
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
            cleanExit(1);
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
