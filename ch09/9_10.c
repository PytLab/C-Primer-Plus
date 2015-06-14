#include <stdio.h>

int main(void)
{
    int n;
    long r;
    long Fibonacci(int);

    puts("Enter sequence number: ");
    while(scanf("%d", &n) == 1)
    {
        r = Fibonacci(n);
        printf("The number %d in Fibonacci sequence: %ld.\n", n, r);
        puts("Enter another sequence number: ");
    }

    return 0;
}

long Fibonacci(int n)
{
    int i, a, b;
    long r;

    if(n <= 2)
        return 1;
    else
    {
        for(i = 3, a = 1, b = 1; i <= n; i++)
        {
            r = a + b;
            a = b;
            b = r;
        }
        return r;
    }
}
