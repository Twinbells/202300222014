/*
*
*Enter a large positive number x, find all prime numbers between 1 and x, and print them out.
*
*/
#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    
    return 1; 
}

int main() {
    int x;
    printf("请输入一个正数x: ");
    scanf("%d", &x);
    for (int i = 2; i <= x; i++) {
        if (isPrime(i)) {
            printf("%d ", i); 
        }
    }
    
    printf("\n"); 
    
    return 0;
}
