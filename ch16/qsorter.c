#include <stdio.h>
#include <stdlib.h>
#define NUM 40

void fillarray(double *, int);
void showarray(double *, int);
int mycomp(const void *, const void *);

int main(void)
{
    double vals[NUM];
    fillarray(vals, NUM);
    puts("Random list: ");
    showarray(vals, NUM);
    qsort(vals, NUM, sizeof(double), mycomp);
    puts("Sorted list: ");
    showarray(vals, NUM);

    return 0;
}

void fillarray(double * a, int n)
{
    int i;

    for(i = 0; i < n; i++)
        a[i] = (double)rand() / ((double)rand() + 0.1);
}

void showarray(double * a, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%9.4f ", a[i]);
        if((i + 1) % 6 == 0)
            putchar('\n');
    }
    putchar('\n');
}

int mycomp(const void * p1, const void * p2)
{
    double * a1, * a2;

    a1 = (double *)p1;
    a2 = (double *)p2;
    if(*a1 > *a2)
        return -1;
    else if(*a1 == *a2)
        return 0;
    else
        return 1;
}
