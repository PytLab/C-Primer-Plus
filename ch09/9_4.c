#include <stdio.h>

int main(void)
{
    float a, b, h;
    float harmmean(float, float);

    puts("Enter two nonzero numbers: ");
    while(scanf("%f%f", &a, &b) != 2 || (a == 0.0 || b == 0.0))
        puts("TWO NONZERO numbers: ");
    h = harmmean(a, b);

    printf("harmmean of %.2f and %.2f: %.2f.\n", a, b, h);

    return 0;
}

float harmmean(float a, float b)
{
    return 1.0/((1.0/a + 1.0/b)/2.0);
}