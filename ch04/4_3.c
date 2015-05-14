#include <stdio.h>

int main(void)
{
    float i;

    printf("Enter a float number: \n");
    scanf("%f", &i);

    printf("The input is %.1f or %.1e\n", i, i);
    printf("The input is %+.3f or %.3E\n", i, i);

    return 0;
}