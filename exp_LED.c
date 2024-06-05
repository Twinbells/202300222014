/*
*
*LED
*
*/
#include <stdio.h>
#include <unistd.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"

int main() {
    int position = 0; 
    int direction = 1; 

    while (1) { 
        
        printf("\033[H\033[J");
        
        printf(ANSI_COLOR_GREEN);
        
        for (int i = 0; i < position; i++) {
            printf(" ");
        }

        printf("ahahahaha\n");
        
        printf(ANSI_COLOR_RESET);

        position += direction;

        if (position >= 80) { 
            direction = -1; 
        } else if (position <= 0) { 
            direction = 1;
        }

        usleep(100000); 
    } 

    return 0;
}
