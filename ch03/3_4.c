#include <stdio.h>

int main(void)
{
    float i;

    printf("Enter a float number: \n");
    scanf("%f", &i);

    printf("The input is %f or %e.\n", i, i);

    return 0;
}