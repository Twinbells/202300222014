/*
*
*Matrix Digital rain
*
*/

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define WIDTH 960
#define HEIGHT 640
#define STR_SIZE 25
#define STR_NUM 128
#define STR_WIDTH 15

typedef struct {
    int x, y;
    int speed;
    char str[STR_SIZE + 1]; 
} Rain;

Rain rain[STR_NUM];

char CreateChar() {
    int flag = rand() % 3;
    char temp;
    if (flag == 0) {
        temp = rand() % 26 + 'a';
    } else if (flag == 1) {
        temp = rand() % 26 + 'A';
    } else {
        temp = rand() % 10 + '0';
    }
    return temp;
}

void InitRains() {
    for (int i = 0; i < STR_NUM; i++) {
        rain[i].x = i * STR_WIDTH;
        rain[i].y = rand() % HEIGHT;
        rain[i].speed = rand() % 5 + 5;
        for (int j = 0; j < STR_SIZE; j++) {
            rain[i].str[j] = CreateChar();
        }
        rain[i].str[STR_SIZE] = '\0'; 
    }
}
void DrawRains() {  
    clear();  
    start_color();  
    attron(COLOR_PAIR(1)); 
    for (int i = 0; i < STR_NUM; i++) {  
        for (int j = 0; j < STR_SIZE && rain[i].y - j * STR_WIDTH > 0; j++) {   
            mvprintw(rain[i].y - j * STR_WIDTH, rain[i].x, "%c", rain[i].str[j]);  
        }  
    }  
    attroff(COLOR_PAIR(1));  
    refresh();  
}  
void MoveRain()
{
	for (int i = 0; i < STR_NUM; i++)
	{
		rain[i].y += rain[i].speed;
		if (rain[i].y- STR_WIDTH*STR_SIZE > HEIGHT)
		{
			rain[i].y = 0;
		}
	}
}
void ChangeCh()
{
	for (int i = 0; i < STR_NUM; i++)
	{
		rain[rand() % STR_NUM].str[rand() % STR_SIZE] = CreateChar();
	}
}

int main() {
    initscr(); 
    cbreak(); 
    noecho(); 
    keypad(stdscr, TRUE); 
    nodelay(stdscr, TRUE); 

    start_color(); 
    init_pair(1, COLOR_GREEN, COLOR_BLACK); 

    srand(time(NULL)); 
    InitRains(); 

    int ch;
    while ((ch = getch()) != 'q') { 
        UpdateRains(); 
        DrawRains(); 
        usleep(100000);
    }

    endwin(); 
    return 0;
}
