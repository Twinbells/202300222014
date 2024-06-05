/*
*call the two functions,print their return values and print out the value of the global variable
*
*/


#include <stdio.h>
#include "module.h"

int main() {
    printf("f1 returns: %d\n", f1());
    printf("f2 returns: %d\n", f2());
    printf("Global variable value: %d\n", global);
    return 0;
}
