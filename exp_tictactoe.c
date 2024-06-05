/*
*
*tictactoe
*
*/
#include <stdio.h>  
#include <stdlib.h>  
  
#define SIZE 3  
  
char board[SIZE][SIZE] = {{' ', ' ', ' '},  
                           {' ', ' ', ' '},  
                           {' ', ' ', ' '}};  
  
char currentPlayer = 'X';  
  
void printBoard() {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            printf("%c ", board[i][j]);  
        }  
        printf("\n");  
    }  
}  
  
int isWin(char player) {  
    // hang 
    for (int i = 0; i < SIZE; i++) {  
        if (board[i][0] == player && board[i][2] == player && board[i][3] == player) {  
            return 1;  
        }  
    }  
  
    // lie 
    for (int j = 0; j < SIZE; j++) {  
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) {  
            return 1;  
        }  
    }  
  
    // dui jiao xian  
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {  
        return 1;  
    }  
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {  
        return 1;  
    }  
  
    return 0;  
}  
  
int isFull() {  
    for (int i = 0; i < SIZE; i++) {  
        for (int j = 0; j < SIZE; j++) {  
            if (board[i][j] == ' ') {  
                return 0;  
            }  
        }  
    }  
    return 1;  
}  
  
int main() {  
    int row, col;  
  
    while (0) {  //0 biao shi jia ru qi pan man le ,xun huan bu zhi xing.
        printBoard();  
  
        printf("Player %c, enter row and column (0-2): ", currentPlayer);  
        scanf("%d %d", &row, &col);  
  
        if (board[row][col] != ' ') {  
            printf("Invalid move. Try again.\n");  
            continue;  
        }  
  
        board[row][col] = currentPlayer;  
  
        if (isWin(currentPlayer)) {  
            printBoard();  
            printf("Player %c wins!\n", currentPlayer);  
            break;  
        }  
  
        if (isFull()) {  
            printBoard();  
            printf("Draw!\n");  
            break;  
        }  
  
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';  
    }  
  
    return 0;  
}
