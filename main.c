#include "main.h"

int main() {
    char inputData[MAX_LINE_COUNT][MAX_LINE_LENGTH];

    // TODO: Read input code from file
    // TODO: Invalid code inside functions fail silently
    strcpy(inputData[0], "function {\n");
    strcpy(inputData[1], "laaaaaaaser;\n");
    strcpy(inputData[2], "}\n");
    strcpy(inputData[3], "function;\n");
    strcpy(inputData[4], "forward;\n");
    strcpy(inputData[5], "right;\n");
    strcpy(inputData[6], "\0");

    turtle myTurtle;
    myTurtle.x = TURTLE_START_X;
    myTurtle.y = TURTLE_START_Y;
    myTurtle.direction = 1;

    return runtime(&myTurtle, compile(inputData));
}
