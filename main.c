#include "main.h"

int main() {
    char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    // get file
    FILE *inputFileH = fopen("main.broc", "r");
    for (int i = 0; i < MAX_LINE_COUNT; i++) {
        if (fgets(inputData[i], MAX_LINE_LENGTH, inputFileH) == NULL) {
            break;
        }
    }
    fclose(inputFileH);



    turtle myTurtle;
    myTurtle.x = TURTLE_START_X;
    myTurtle.y = TURTLE_START_Y;
    myTurtle.direction = 1;
    {/*
        FILE *outputFileH = fopen("main.brocc", "w");
        fprintf(outputFileH, compile(inputData));
        fclose(outputFileH);
    }*/
    return runtime(&myTurtle, compile(inputData));
}
