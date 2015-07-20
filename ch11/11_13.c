#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char * argv[])
{
    double base;
    int expo;

    base = atof(argv[1]);
    expo = atoi(argv[2]);
    printf("%.2lf**%d = %.2lf\n", base, expo, pow(base, expo));
    
    return 0;
}