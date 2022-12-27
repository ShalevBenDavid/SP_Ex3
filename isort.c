// Created by Shalev Ben David.
#include <stdio.h>

#define SIZE 50

void insertion_sort(int*, int);

int main() {
    int arr[SIZE];
    int num = 0;

    // Create array "arr".
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &num);
        *(arr + i) = num;
    }

    // Sort "arr".
    insertion_sort(arr, SIZE);

    // Print "arr".
    for (int i = 0; i < SIZE; i++) {
        printf("%d", *(arr + i));
    }
    printf("\n");
    return 0;
}

void shift_element(int* arr, int i) {
    while (i > 0) {
        *(arr + i) = *(arr + i - 1);
        i--;
    }
}

void insertion_sort(int* arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (*(arr + j) > *(arr + i)) {
                int save = *(arr + i);
                shift_element(arr + j, i - j);
                *(arr + j) = save;
            }
        }
    }
}