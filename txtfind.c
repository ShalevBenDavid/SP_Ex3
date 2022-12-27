// Created by Shalev Ben David.
#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define TEXT 250

char word[WORD];
char text[TEXT][LINE];

int getWord();
int getLine(char[]);
int substring(char[], char[]);
void print_similar_words();
void A();
void B();

int main() {
    // Save word in "word" array.
    getWord();

    // What option did user chose? A or B.
    char choice;
    choice = getchar();
    getchar();
    getchar();

    // Save text in "text" 2D array.
    for (int i = 0; i < TEXT; i++) {
        if (getLine(text[i]) == 0) {
            break;
        }
    }

    switch (choice) {
        case 'A': A();
        case 'B': B();
        default: printf("invalid choice. You need to choose between A or B");
    }
    printf("\n");
    return 0;
}

// A method that prints all lines in "text" containing "word".
void A() {
    for (int i = 0; i < TEXT; i++) {
        if (substring(word,text[i]) == 1) {
            printf("%s\n", text[i]);
        }
    }
}

void B(){
    print_similar_words();
}

// A method that gets a word from the standard input and saves at "w" array.
int getWord() {
    int length = 0;
    char save;
    while (((save = getchar()) != '\n') && (save != '\t') &&  (save != ' ') && (save != '\r') && (save != EOF)) {
        word[length] = save;
        length++;
    }
    word[length] = '\0';
    return length;
}

// A method that gets a line from the standard input and saves at "s" array.
int getLine(char s[]) {
    int length = 0;
    char save;
    while (((save = getchar()) != '\n') && (save != '\r') && (save != EOF )) {
        s[length] = save;
        length++;
    }
    s[length] = '\0';
    return length;
}

int substring( char str1[], char str2[]) {
    if(strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
}

int similar (char s[], char t[], int n) {
    // If lenS - n != lenT, there's no way for similarity.
    if(strlen(s) - n != strlen(t)) {
        return 0;
    }

    for (int i = 0, j = 0; i < strlen(s); i++) {
        if (s[i] != t[j]) {
            n--;
            if (n < 0) {
                return 0;
            }
        }
        else {
            j++;
        }
    }
    return 1;
}

void print_similar_words() {
    char currentWord[WORD] = {'\0'};
    for (int i = 0; i < TEXT; i++) {
        for (int j = 0; j < strlen(text[i]); j++) {
            int k = 0;
            while (text[i][j] != ' ') {
                currentWord[k++] = text[i][j];
            }
            currentWord[k] = '\0';
            if(similar(currentWord, word, 1) == 1) {
                printf("%s\n", currentWord);
            }
        }
    }
}