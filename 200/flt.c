#include <stdio.h>

void det_larg_small(float *store)
{
    float larg = store[0];
    float small = store[0];

    for (int i = 0; i < 10; i++)
    {
        if (store[i] < small)
        {
            small = store[i];
        }
        if (store[i] > larg)
        {
            larg = store[i];
        }
    }
    printf("The largest number is %.2f\n", larg);
    printf("The smallest number is %.2f\n", small);
}

int main()
{
    float store[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %d:  ", i + 1);
        scanf("%f", &store[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        printf("The number %d is %.2f\n", i + 1, store[i]);
    }
    printf("\n");
    det_larg_small(store);
    return 0;
}