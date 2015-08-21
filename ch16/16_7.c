#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

double * new_d_array(int, ...);
void show_array(const double *, int);

int main(void)
{
    double * p1, * p2;

    p1 = new_d_array(5, 1.2, 2.3, 3.4, 4.5, 5.6);
    p2 = new_d_array(4, 100.0, 20.00, 8.08, -1980.0);
    show_array(p1, 5);
    show_array(p2, 4);
    free(p1);
    free(p2);

    return 0;
}

double * new_d_array(int n, ...)
{
    double * array = (double *)malloc(n*sizeof(double));
    va_list ap;  /*用于存放参数的变量*/

    va_start(ap, n);
    for(int i = 0; i < n; i++)
        array[i] = va_arg(ap, double);
    va_end(ap);

    return array;
}

void show_array(const double * array, int n)
{
    for(int i = 0; i < n; i++)
        printf("%.2f ", array[i]);
    putchar('\n');
}
