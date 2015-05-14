#include <stdio.h>

int main(void)
{
    int weeks, days, left_days;
    const int days_per_week = 7;

    printf("Enter number of days(minus to stop): \n");
    while(scanf("%d", &days) == 1 && days > 0)
    {
        left_days = days % days_per_week;
        weeks = days / days_per_week;
        printf("%d days are %d weeks, %d days\n", days, weeks, left_days);
        puts("Enter another number: ");
    }

    return 0;
}