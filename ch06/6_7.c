#include <stdio.h>

int main(void)
{
    float f1, f2, res;

    puts("Enter 2 float numbers(q to quit): ");

    while(scanf("%f%f", &f1, &f2) == 2)
    {
        res = (f1 - f2)/(f1*f2);
        printf("%f\n", res);
        puts("Enter another pair of float numbers: ");
    }
    puts("Bye!");

    return 0;
}