/*
*The input is a single English character, and the output is the pattern representation of the English character
*/
#include <stdio.h>

void print_char_pattern(char c) {
    const char *red = "\033[31m";
    const char *reset = "\033[0m";

    switch (c) {
        case 'E':
            printf("%s******\n", red);
            printf("%s*\n", red);
            printf("%s******\n", red);
            printf("%s*\n", red);
            printf("%s******\n", red);
            printf("%s\n", reset);
            break;
        case 'A':
            printf("%s   *   \n", red);
            printf("%s  * *  \n", red);
            printf("%s * * * \n", red);
            printf("%s*     *\n", red);
            printf("%s\n", reset);
            break;
        case 'H':
            printf("%s*    *\n", red);
            printf("%s*    *\n", red);
            printf("%s*    *\n", red);
            printf("%s******\n", red);
            printf("%s*    *\n", red);
            printf("%s*    *\n", red);
            printf("%s\n", reset);
            break;
        default:
            printf("Unsupported character for pattern output.\n");
            break;
    }
}

int main() {
    char c;
    printf("Enter an uppercase English letter (E, A, or H): ");
    scanf(" %c", &c); 
    print_char_pattern(c);

    return 0;
}
