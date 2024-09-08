#include <stdio.h>

int main() {
    int width = 30;
    int height  = 10;
    // ;et's print the flag of Nigeria
    // let * represents green color and white space represents white color

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 3; j++) {
                printf("*");
        }
        for (int j = 0; j < width / 3; j++) {
                printf(" ");
        }
        for (int j = 0; j < width / 3; j++) {
                printf("*");
        }
        printf("\n");
    }
    return 0;
}