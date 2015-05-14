#include <stdio.h>

int main(void)
{
    float i;
    void cube(float);

    puts("Enter a float number: ");
    scanf("%f", &i);
    cube(i);

    return 0;
}

void cube(float i)
{
    printf("%f\n", i*i*i);
}