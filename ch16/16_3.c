#include <stdio.h>
#include <math.h>

#define PI (4*atan(1))
#define DEG_TO_RAD (PI/180)

int main(void)
{
    float r, theta;

    puts("Enter length and angle: ");
    while(scanf("%f%f", &r, &theta) == 2)
    {
        printf("(%f, %f)\n", r*cos(DEG_TO_RAD*theta), r*sin(DEG_TO_RAD*theta));
        puts("Enter again: ");
    }

    return 0;
}
