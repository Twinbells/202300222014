/*
*
*Determine whether a number is prime
*
*/



#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    
    return 1; 
}

int main() {
    int num;
    printf("Please enter a number: ");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
