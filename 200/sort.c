#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
 return (*(int *)a - *(int *)b);
}

void sortarray(int arr[]){
    qsort(arr, 10, sizeof(int), compare);
}

int main(void) {
    int lt_sum  = 0;
    int gt_sum = 0;
    int arr[10] = {1, -2, -4, 5 ,6 ,8 ,9 ,4 ,3 -9, 9};

    for(int i = 0; i < 10; i++){
        if (arr[i] >= 0){
            gt_sum += arr[i];
        } else {
            lt_sum += arr[i];
        }
    }
    sortarray(arr);

    for (int i =0; i< 10; i++){
        if (i == 9) {
             printf("%d\n",  arr[i]);
        } else {
             printf("%d, ",  arr[i]);
        }
    }
    printf("\nThe postive sum is %d and negative sum is %d\n", gt_sum, lt_sum);
    return 0;
}