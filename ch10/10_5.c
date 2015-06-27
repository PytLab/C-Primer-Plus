#include <stdio.h>

int main(void)
{
    double diff;
    double arr[10] = {1.0, 2.0, 3.0, 4.0, 20.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    double get_diff(const double *, int);

    diff = get_diff(arr, 10);
    printf("Differece: %.1lf\n", diff);

    return 0;
}

double get_diff(const double * arr, int n)
{
    double min = arr[0], max = arr[0];
    int i;
    for(i = 1; i < n; i++)
    {
        if(arr[i] < min)
            min = arr[i];
        else if(arr[i] > max)
            max = arr[i];
    }

    return max - min;
}