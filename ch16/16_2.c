#include <stdio.h>
#define HARM_AVG(X, Y) ((1.0 / (1.0/(X) + 1.0/(Y))) / 2.0)

int main(void)
{
    float a, b, avg;

    puts("Enter 2 float numbers:");
    while(scanf("%f%f", &a, &b) == 2)
    {
        avg = HARM_AVG(a, b);
        printf("HARM_AVG: %.2f\n", avg);
        puts("Another 2 float numbers: ");
    }

    return 0;
}
