#include <stdio.h>
#include <math.h>

int main(void)
{
    int count, i;
    int isprime(int);

    puts("Enter a integer: ");
    scanf("%d", &i);

    if(i == 2)
    {
        printf("2\n");
        return 0;
    }
    else
    {
        printf("2 ");
        for(count = 3; count <= i; count += 2)  //只对奇数进行判断
        {
            if(isprime(count))
                printf("%d ", count);
            else
                continue;
        }
        putchar('\n');
    }

    return 0;
}

int isprime(int number)
{
    int i;

    for(i = 2; i <= sqrt(number); i++)
    {
        if(number % i == 0)
            return 0;
        else
            continue;
    }

    return 1;
}