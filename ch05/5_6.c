#include <stdio.h>

int main(void)
{
    int sum = 0, count = 1, income;

    while(count++ <= 10)
    {
        printf("Day %d, your income: \n", count - 1);
        scanf("%d", &income);
        sum += income*income;
    }

    printf("10 days passed, you earned $%d\n", sum);

    return 0;
}