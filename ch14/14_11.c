#include <stdio.h>
#include <math.h>
#define ALEN 5

typedef float (* FPTR)(float);

void transform(float *, float *, int, FPTR);
void putarr(float *, int);
float dbl(float);

int main(void)
{
    float source[ALEN] = {0.5, 1.5, 2.0, 3.5, 2.3};
    float target[ALEN];
    transform(source, target, ALEN, dbl);
    printf("source: ");
    putarr(source, ALEN);
    printf("target: ");
    putarr(target, ALEN);

    return 0;
}

void transform(float * source, float * target, int n, FPTR pfunc)
{
    int i;

    for(i = 0; i < n; i++)
        target[i] = (*pfunc)(source[i]);
}

void putarr(float * arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    putchar('\n');
}

float dbl(float x)
{
    return 2*x;
}
