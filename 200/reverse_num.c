#include <stdio.h>

int main(void){
    int rem, num;
    printf("Enter a number greater than 10:\n");
    scanf("%d", &num);

    while (num > 0){
        rem = num % 10;
        printf("%d", rem);
        num = num / 10;
    }
    printf("\n"); 
    return 0;
}