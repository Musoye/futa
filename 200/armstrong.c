#include <stdio.h>

int cube(int y) {
    return y * y *y;
}

int armstrong(int y){
    int num = y;
    int third = num % 10;
    num /= 10;
    int second = num % 10;
    num /= 10;
    int first = num % 10;
    if ((cube(first) + cube(second) + cube(third)) == y)
    {
        return 1;
    }
    return 0;
}

int main(void){

     for (int c = 100; c < 1000; c++) {
        if (armstrong(c)){
            printf("%d\n", c);
        }
     }

    return 0;
}