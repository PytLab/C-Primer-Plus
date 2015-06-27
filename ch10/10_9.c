#include <stdio.h>

int main(void)
{
    int arr1[4] = {1, 2, 3, 4};
    int arr2[4] = {2, 3, 4, 5};
    int sum[4];

    void sum_arr(const int *, const int *, int *, int);
    void print_arr(const int *, int);

    sum_arr(arr1, arr2, sum, 4);
    puts("array1: ");
    print_arr(arr1, 4);
    puts("array2: ");
    print_arr(arr2, 4);
    puts("sum array: ");
    print_arr(sum, 4);

    return 0;
}

void sum_arr(const int * arr1, const int * arr2, int * sum, int n)
{
    int i;
    for(i = 0; i < n; i++)
        sum[i] = arr1[i] + arr2[i];
}

void print_arr(const int * array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("array[%d] = %d\n", i, array[i]);
}
