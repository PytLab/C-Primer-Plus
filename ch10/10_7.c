#include <stdio.h>

int main(void)
{
    double source[7] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7};
    double target[3];
    void copy_ptr(const double *, double *, int, int);
    void print_arr(const double *, int);
    
    copy_ptr(source, target, 3, 3);\
    puts("source array: ");
    print_arr(source, 7);
    puts("target arry: ");
    print_arr(target, 3);

    return 0;
}

void copy_ptr(const double * source, double * target, int start, int num)
{
    int i;
    for(i = 0; i < num; i++)
        target[i] = source[start-1+i];
}

void print_arr(const double * array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("array[%d] = %.1lf\n", i, array[i]);
}