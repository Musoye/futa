#include <stdio.h>

int main(void){
    int x;
    int holder = 1;
    

    printf("Enter the number of height you want: ");
    scanf("%d", &x);


    for (int i = 1; i <= x; i++){
        for (int j =0; j < i; j++){
            printf("%d", holder);
            holder++;
        }
        printf("\n");
    }
    return 0;
}