#include <stdio.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int num = rand() % 9;
    int enter;
    printf("Enter a number: \n");
    scanf("%d", &enter);
    while (num != enter){
        puts("Does not equal");
        printf("Enter a number: \n");
        scanf("%d", &enter);  
    }
    printf("correct, %d\n", num);
    return 0;
}
