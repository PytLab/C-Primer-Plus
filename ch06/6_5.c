#include <stdio.h>

int main(void)
{
    int min, max, row_num;

    puts("Enter a integer as upper limit:");
    scanf("%d", &max);
    puts("And the lower limit:");
    scanf("%d", &min);

    for(row_num = min; row_num <= max; row_num++)
    {
        printf("%8d", row_num);
        printf("%8ld", row_num*row_num);
        printf("%8ld", row_num*row_num*row_num);
        putchar('\n');
    }

    return 0;
}