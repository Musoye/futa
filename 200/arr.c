#include <stdio.h>

int main()
{
    float arr[8] = {4, 7, 8, 9, 10, 12, 13, 20};
    float sum = 0, average;

    for (int i = 0; i < 8; i++)
    {
        sum += arr[i];
    }
    average = sum / 8;

    printf("The sum of the array is %.2f \n", sum);
    printf("The average of the array is %.2f \n", average);
    return 0;
}