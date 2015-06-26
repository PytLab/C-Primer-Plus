#include <stdio.h>

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 20, 5, 6, 7, 8, 9};
    int res;
    int get_max(const int *, int n);

    res = get_max(arr, 10);
    printf("The max number is: %d.\n", res);

    return 0;
}

int get_max(const int * arr, int n)
{
    int i, max = arr[0];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}
