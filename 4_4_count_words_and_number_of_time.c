/*
*receives a English string,counts the words and the number of times those words have appeared in each line, and the total number of times they have appeared in the user's input.
*
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 1024
#define MAX_WORDS 1000 

typedef struct {
    char word[50]; 
    int line_counts[MAX_LINES]; 
    int total_count; 
} Word;

Word words[MAX_WORDS];
int word_count = 0; 

void add_word(char *word, int line_num);
void print_statistics();

int main() {
    char *lines[MAX_LINES]; 
    char input[MAX_LINE_LENGTH];
    int line_num = 0;

    for (int i = 0; i < MAX_LINES; i++) {
        lines[i] = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    printf("Enter lines of text. Type 'END' to finish:\n");
    while (fgets(input, MAX_LINE_LENGTH, stdin) != NULL && strcmp(input, "END\n") != 0) {
        input[strcspn(input, "\n")] = 0;
        strcpy(lines[line_num++], input);
    }

    for (int i = 0; i < line_num; i++) {
        char *token = strtok(lines[i], " \t\n\r,.;:?!-");
        while (token != NULL) {
            add_word(token, i);
            token = strtok(NULL, " \t\n\r,.;:?!-");
        }
    }

    print_statistics();

    for (int i = 0; i < MAX_LINES; i++) {
        free(lines[i]);
    }

    return 0;
}

void add_word(char *word, int line_num) {
    for (int i = 0; i < word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].line_counts[line_num]++;
            words[i].total_count++;
            return;
        }
    }

    strcpy(words[word_count].word, word);
    for (int j = 0; j < MAX_LINES; j++) {
        words[word_count].line_counts[j] = 0;
    }
    words[word_count].line_counts[line_num] = 1;
    words[word_count].total_count = 1;
    word_count++;
}

void print_statistics() {
    for (int i = 0; i < word_count; i++) {
        printf("Word: %s, Total count: %d", words[i].word, words[i].total_count);
        printf(", Appears in lines: ");
        for (int j = 0; j < MAX_LINES; j++) {
            if (words[i].line_counts[j] > 0) {
                printf("%d ", j+1); 
            }
        }
        printf("\n");
    }
}
