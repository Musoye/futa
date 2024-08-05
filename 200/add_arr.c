#include <stdio.h>

// add 3x2 matrices using arrays
int main(void)
{
    int a[3][2], b[3][2], c[3][2];
    printf("Enter the elements of the first matrix: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter element a %d, %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of the second matrix: \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter element b %d, %d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("The sum of the matrices is: \n");
    printf("[");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
            {
                printf("%d", c[i][j]);
            }
            else
            {
                printf("%d, ", c[i][j]);
            }
        }
        if (i == 2)
        {
            printf("]\n[");
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}