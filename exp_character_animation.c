/*
*
*Character animation
*
*/
#include <stdio.h>
#include <unistd.h> 

#define COLS 80

void clear_line() {
    printf("\r");
    for (int i = 0; i < COLS; ++i) {
        printf(" ");
    }
    printf("\r");
}

int main() {
    int x = 0;
    
    while (1) {
        clear_line();
        printf("%*c", x, '*'); 
        

        usleep(30000); 
        
        if (x == COLS - 1) {
            x = 0; 
        } else {
            x++;
        }
    }

    return 0;
}
