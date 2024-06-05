/*
*
*Random number rolling
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 80
#define NUM_DIGITS 10

void print_digits(int y, int digits[NUM_DIGITS]) {
    for (int x = 0; x < SCREEN_WIDTH && x < NUM_DIGITS; x++) {
        printf("%d ", digits[x]);
    }
    printf("\r\n");
}

int main() {
    srand(time(0));

    int digits[NUM_DIGITS];
    for (int i = 0; i < NUM_DIGITS; i++) {
        digits[i] = rand() % 10;
    }

    while (1) {
        for (int i = SCREEN_HEIGHT - 1; i > 0; i--) {
            print_digits(i, digits);
            for (int j = 0; j < NUM_DIGITS - 1; j++) {
                digits[j] = digits[j + 1]; 
            }
            digits[NUM_DIGITS - 1] = rand() % 10;
        }
        print_digits(0, digits);
        
    }

    return 0;
}
