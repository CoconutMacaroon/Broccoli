#include "main.h"

int main() {
    // set color to red
    printf("\033[31m");

    // print text
    printf("INFO: All numbers start counting at zero\n");

    // and reset the color
    printf("\033[0m");
    return compile();
}
