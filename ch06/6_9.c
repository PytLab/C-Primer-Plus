#include <stdio.h>

int main(void)
{
    int i, min, max;
    long sum = 0;

    printf("Enter lower and upper integer limits: ");
    while(scanf("%d%d", &min, &max) == 2 && min < max)
    {
        for(i = min; i <= max; i++)
            sum += (long)(i*i);
        printf("The sums of the squares from %d to %d is %ld\n", min, max, sum);
        printf("Enter next set of limits: ");
    }
    puts("Done");

    return 0;
}