#include <stdio.h>

int main(void)
{
    double F;
    void Temperature(double);

    puts("Enter a Fahrenheit temperature(q to quit):");
    while(scanf("%lf", &F) == 1)
    {
        Temperature(F);
        puts("Enter another temperature: ");
    }

    return 0;
}

void Temperature(double F)
{
    const double C_intercept = 32.0;
    const double C_slope = 1.8;
    const double K_intercept = 273.16;
    double K, C;                           //Kelvin and Celsius

    C = C_slope*F + C_intercept;
    K = C + K_intercept;

    printf("Celsius: %.2lf\n", C);
    printf("Kelvin: %.2lf\n", K);
}