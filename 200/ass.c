#include <stdio.h>

int main(){
    int x = 2, z = 4, y;
    //float y;

    //y = x++ + ++x;
    //y = ++x + ++x + ++x;
    //y = ++x + ++x;
    //y = x > z;
    //y = x > z ? x :z;
    //y = x & z;
    y = (x >> 2) + (z >> 1);
    printf("%u\n", y);
    return 0;
}