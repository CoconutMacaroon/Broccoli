#include "main.h"

int main() {

    char inputData[maxLineCount][maxLineLength];

    // TODO: Read input code from file
    strcpy(inputData[0], "function {\n");
    strcpy(inputData[1], "laser;\n");
    strcpy(inputData[2], "}\n");
    strcpy(inputData[3], "function;\n");
    strcpy(inputData[4], "forward;\n");
    strcpy(inputData[5], "right;\n");
    strcpy(inputData[6], "\0");

    turtle myTurtle;
    myTurtle.x = turtleStartX;
    myTurtle.y = turtleStartY;
    myTurtle.direction = 1;
    char *compiledCode = compile(inputData);

    // here it is NULL
    runtime(&myTurtle, compiledCode);
}
