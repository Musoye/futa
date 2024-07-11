#include <stdio.h>

/**
 * main - entry point of the program
 * 
 * Return: 0
 */
int main(void){
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);
    while (num > 0) {
        num -= 2;
    }
    if (num == 0) {
        printf("The number is even\n");
    } else {
        printf("The number is odd\n");
    }
    return 0;
}