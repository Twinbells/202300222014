/*
*
*Input a character and output a value representing each bit of that character byte
*
*/
#include <stdio.h>  
  
int main() {  
    char ch;  
    printf("Enter a character: ");  
    scanf("%c", &ch);   
    for (int i = 7; i >= 0; --i) {  
        int bit = (ch >> i) & 1;  
        printf("The %s bit is %d,\n",  
               (i == 7) ? "eighth" :  
               (i == 0) ? "first" :  
               (i == 6) ? "seventh" :  
               (i == 5) ? "sixth" :  
               (i == 4) ? "fifth" :  
               (i == 3) ? "fourth" :  
               (i == 2) ? "third" :  
               (i == 1) ? "second" : "other"); 
    }  
  
    return 0;  
}
