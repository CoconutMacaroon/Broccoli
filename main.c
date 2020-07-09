#include "main.h"

int main() {
    // set color to red
    printf("\033[31m");

    // print text
    printf("INFO: All numbers start counting at zero");

    // and reset the color
    printf("\033[0m");
    return compile();
}


/*
 * f = forward
 * l = left
 * r = right
 * L = laser
 * 0 = <none>    the runtime should ignore characters that are zeros
 * */
