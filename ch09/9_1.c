#include <stdio.h>

int main(void)
{
    double a, b, m;
    double min(double, double);

    printf("Enter 2 numbers: ");
    scanf("%lf%lf", &a, &b);

    m = min(a, b);

    printf("The smaller number between %.2lf and %.2lf is %.2lf.\n", a, b, m);

    return 0;
}

double min(double a, double b)
{
    return a > b ? a: b;
}
