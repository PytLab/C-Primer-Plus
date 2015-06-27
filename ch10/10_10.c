#include <stdio.h>

int main(void)
{
    double arr[3][5] = {
        {4.3, 4.3, 4.3, 3.0, 2.0},
        {8.5, 8.2, 1.2, 1.6, 2.4},
        {9.1, 8.5, 6.7, 4.3, 2.1},
    };

    void print_arr(const double (*)[5], int);
    void double_arr(double (*)[5], int);

    puts("before doubling: ");
    print_arr(arr, 3);
    double_arr(arr, 3);
    puts("after doubling: ");
    print_arr(arr, 3);

    return 0;
}

void print_arr(const double (* arr)[5], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 5; j++)
            printf("%-5.1lf", arr[i][j]);
        putchar('\n');
    }
}

void double_arr(double (* arr)[5], int n)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < 5; j++)
            arr[i][j] *= 2;
    }
}
