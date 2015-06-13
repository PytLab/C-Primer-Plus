#include <stdio.h>

int main(void)
{
    double m, result;
    int p;
    double power(double, int);

    puts("Enter 2 number(float, int): ");
    scanf("%lf%d", &m, &p);
    result = power(m, p);
    printf("%.2lf^%d = %.2lf\n", m, p, result);

    return 0;
}

double power(double m, int p)
{
    double pow = 1;
    int i, negative = 0;

    if(m == 0.0)
        return 0.0;
    else
    {
        if(p < 0)
        {
            negative = 1;
            p *= -1;
        }

        /*用递归代替循环*/
        if(p > 0)
            pow = m*power(m, p - 1);
        /*
        else
            pow = 1;
        */
        if(negative)
            pow = 1.0/pow;

        return pow;
    }
}