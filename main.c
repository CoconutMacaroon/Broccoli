#include "main.h"

int main() {
    char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH];

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
        while(compiledCode[i] != '0') {
            fputc(compiledCode[i], outputFileH);
            ++i;
        }
        fclose(outputFileH);
    }

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
