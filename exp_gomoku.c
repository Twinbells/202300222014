/*
*
*gomoku(wu_zi_qi)
*
*/
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 15
#define WINNING_LENGTH 5

typedef enum {
    EMPTY,
    PLAYER_X,
    PLAYER_O
} CellState;

CellState board[BOARD_SIZE][BOARD_SIZE];
void print_board() {
    printf("  ");
    for (int j = 0; j < BOARD_SIZE; ++j) {
        printf("%2d ", j + 1);
    }
    printf("\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("%2d ", i + 1); 
        for (int j = 0; j < BOARD_SIZE; ++j) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(".  ");
                    break;
                case PLAYER_X:
                    printf("X  ");
                    break;
                case PLAYER_O:
                    printf("O  ");
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool check_win(CellState player, int x, int y) {
    int count = 1;
    for (int i = x - 1; i >= 0 && board[i][y] == player; --i, ++count);
    for (int i = x + 1; i < BOARD_SIZE && board[i][y] == player; ++i, ++count);
    if (count >= WINNING_LENGTH) {
        return true;
    }
    count = 1;
    for (int j = y - 1; j >= 0 && board[x][j] == player; --j, ++count);
    for (int j = y + 1; j < BOARD_SIZE && board[x][j] == player; ++j, ++count);
    if (count >= WINNING_LENGTH) {
        return true;
    }
    count = 1;
    for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && board[i][j] == player; --i, --j, ++count);
    for (int i = x + 1, j = y + 1; i < BOARD_SIZE && j < BOARD_SIZE && board[i][j] == player; ++i, ++j, ++count);
    if (count >= WINNING_LENGTH) {
        return true;
    }
    count = 1;
    for (int i = x - 1, j = y + 1; i >= 0 && j < BOARD_SIZE && board[i][j] == player; --i, ++j, ++count);
    for (int i = x + 1, j = y - 1; i < BOARD_SIZE && j >= 0 && board[i][j] == player; ++i, --j, ++count);
    if (count >= WINNING_LENGTH) {
        return true;
    }
    return false;
}

int main() {
    int player_turn = PLAYER_X;
    bool game_over = false;

    printf("Gomoku Game (Player X vs Player O)\n\n");

    while (!game_over) {
        print_board();
        printf("Player %c's turn: Enter row and column (1-15): ",
               player_turn == PLAYER_X ? 'X' : 'O');

        int row, col;
        scanf("%d %d", &row, &col);
        --row, --col; 

        board[row][col] = player_turn;

        if (check_win(player_turn, row, col)) {
            printf("Player %c wins!\n", player_turn == PLAYER_X ? 'X' : 'O');
            game_over = true;
        } else {
            player_turn = (player_turn == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    if (!game_over) {
        printf("It's a draw!\n");
    }

    return 0;
}
