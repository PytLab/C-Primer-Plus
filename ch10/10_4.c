#include <stdio.h>

int main(void)
{
    double arr[10] = {1.0, 2.0, 3.0, 4.0, 20.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    int res;
    int get_max_index(const double *, int n);

    res = get_max_index(arr, 10);
    printf("The index of max number is: %d.\n", res);

    return 0;
}

int get_max_index(const double * arr, int n)
{
    int i, max_idx = 0;
    double max = arr[max_idx];

    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            max_idx = i;
        }
    }

    return max_idx;
}