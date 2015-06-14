#include <stdio.h>

int main(void)
{
    unsigned long number, base;
    void to_base_n(unsigned long, unsigned long);

    puts("Enter two integers(number and base): ");
    while(scanf("%ld%ld", &number, &base) == 2)
    {
        printf("Equivalent: ");
        to_base_n(number, base);
        putchar('\n');
        puts("Enter another two integers(number and base): ");
    }
}

void to_base_n(unsigned long n, unsigned long base)
{
    long r;  //存放每一级递归的余数
    r = n % base;
    if(n >= base)
        to_base_n(n/base, base);
    printf("%ld", r);

    return;
}
