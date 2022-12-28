// Created by Shalev Ben David.
#include <stdio.h>
#include <string.h>

#define WORD 30
#define LINE 256
#define TEXT 250

char word[WORD] = {'\0'};
char text[TEXT][LINE] = {'\0'};

int getWord();
int getLine(int);
int substring(char[], char[]);
void print_similar_words();
void A();
void B();

int main() {
    // Save word in "word" array.
    getWord();

    // What option did user chose? A or B.
    char choice = (char) getchar();
    getchar();
    getchar();

    // Save text in "text" 2D array.
    for (int i = 0; i < TEXT; i++) {
        if (getLine(i) == 0) {
            break;
        }
    }

    switch (choice) {
        case 'a':
            A();
            break;
        case 'b':
            B();
            break;
        default:
            printf("invalid choice. You need to choose between A or B");
            break;
    }
    return 0;
}

// A method that prints all lines in "text" containing "word".
void A() {
    for (int i = 0; i < TEXT; i++) {
        if (substring(text[i],word) == 1) {
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
    int c;
    while (((c = getchar()) != '\n') && (c != '\t') && (c != '\r') && (c != ' ') && (c != EOF)) {
        word[length++] = (char) c;
    }
    word[length] = '\0';
    return length;
}

// A method that gets a line from the standard input and saves at "s" array.
int getLine(int row) {
    int length = 0;
    int c;
    while (((c = getchar()) != '\n') && (c != '\r') && (c != EOF) && (length < LINE - 1)) {
        text[row][length++] = (char) c;
    }
        text[row][length] = '\0';
    return length;
}

int substring( char str1[], char str2[]) {
    if(strstr(str1, str2) != NULL) {
        return 1;
    }
    return 0;
}

int similar (char s[], char t[], int n) {
    // If the words are identical then return 1.
    if (strcmp(s, t) == 0) {
        return 1;
    }
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
    char currentWord[WORD] = {0};
    for (int i = 0; i < TEXT; i++) {
        for (int j = 0; j < strlen(text[i]); j++) {
            int k = 0;
            while ((text[i][j] != '\0') && (text[i][j] != ' ')) {
                currentWord[k++] = text[i][j++];
            }
            currentWord[k] = '\0';
            if(similar(currentWord, word, 1) == 1) {
                printf("%s\n", currentWord);
            }
        }
    }
}