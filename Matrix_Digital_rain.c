/*
*
*Matrix Digital rain
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define COLUMNS 20
#define DROP_COUNT 20
#define INTERVAL 30000 //jian_ge_shi_jian_(wei_miao)
#define COLS 120
#define DROP_LENGTH 2 
#define ALPHABET_LEN (sizeof(alphabet) - 1) // 

const char *alphabet = "abcdefghijklmMNOPQRSTUVWXYZ !@#$%&";

typedef struct {
    int y;
    char c[DROP_LENGTH];
} Drop;

Drop drops[COLUMNS][DROP_COUNT];

void clear_screen() {
    printf("\033[H\033[J");
}

void set_color(int color) {
    switch (color) {
        case 1:
            printf("\033[32;40m"); // lv_se_bei_jing_hei_se_wen_zi
            break;
        case 2:
            printf("\033[32m"); // lv_se_wen_zi
            break;
        default:
            printf("\033[0m"); // hui_fu_mo_ren_yan_se
            break;
    }
}

void initialize_drops(Drop drops[][DROP_COUNT], int columns, const char *alphabet, int alphabet_len) {
    for (int col = 0; col < columns; ++col) {
        for (int i = 0; i < DROP_COUNT; ++i) {
            drops[col][i].y = rand() % (34 - DROP_LENGTH);
            for (int j = 0; j < DROP_LENGTH; ++j)
                drops[col][i].c[j] = alphabet[rand() % alphabet_len];
        }
    }
}

void update_drops(Drop drops[][DROP_COUNT], int columns) {
    for (int col = 0; col < columns; ++col) {
        for (int i = 0; i < DROP_COUNT; ++i) {
            for (int j = 0; j < DROP_LENGTH; ++j) {
                if (++drops[col][i].y + j >= 34) {
                    drops[col][i].y = 0;
                    for (int k = 0; k < DROP_LENGTH; ++k)
                        drops[col][i].c[k] = alphabet[rand() % ALPHABET_LEN];
                }
            }
        }
    }
}

void draw_rain(Drop drops[][DROP_COUNT], int columns, int cols) {
    clear_screen();
    for (int col = 0; col < columns; ++col) {
        for (int i = 0; i < DROP_COUNT; ++i) {
            set_color(1);
            for (int j = 0; j < DROP_LENGTH; ++j) {
                printf("\033[%d;%dH%c", drops[col][i].y + j, col * (cols / columns), drops[col][i].c[j]);
            }
            printf("\033[0G"); // hui_dao_hang_shou
        }
    }
}

int main() {
    srand(time(NULL));
    initialize_drops(drops, COLUMNS, alphabet, ALPHABET_LEN);

    bool running = true;
    while (running) {
        draw_rain(drops, COLUMNS, COLS);
        update_drops(drops, COLUMNS);
        usleep(INTERVAL);

        int ch = getchar();
        if (ch == 'q' || ch == EOF) {
            running = false;
        } else {
            set_color(0); // chong_zhi_yan_se
        }

        // qing_li_huan_chong_qu
        while (getchar() != '\n');
    }

    return 0;
}
