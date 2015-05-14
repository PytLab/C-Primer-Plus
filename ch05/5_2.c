#include <stdio.h>

int main(void)
{
    int i, max;

    printf("Enter an integer: \n");
    scanf("%d", &i);
    max = i + 10;

    for(; i <= max; i++)
    {
        printf("%d\t", i);
    }
    printf("\n");

    return 0;
}