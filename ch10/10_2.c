#include <stdio.h>

int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5], target2[5];
    void copy_arr(const double *, double *, int);
    void copy_ptr(const double *, double *, int);
    void print_arr(const double *, int);

    copy_arr(source, target1, 5);
    copy_ptr(source, target2, 5);

    //打印复制结果
    puts("target1: ");
    print_arr(target1, 5);
    putchar('\n');
    puts("target2: ");
    print_arr(target2, 5);

    return 0;
}

void copy_arr(const double * source, double * target, int n)
{
    int i;
    for(i = 0; i < n; i++)
        target[i] = source[i];
}

void copy_ptr(const double * source, double * target, int n)
{
    int i;
    for(i = 0; i < n; i++)
        *(target + i) = *(source + i);
}

void print_arr(const double * array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("array[%d] = %.1lf\n", i, array[i]);
}
