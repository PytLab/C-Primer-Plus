#include <stdio.h>
#define YEAR 3.156e7

int main(void)
{
    int age;
    double sec;

    printf("Enter your age: \n");
    scanf("%d", &age);

    sec = age*YEAR;

    printf("There are %g sec\n", sec);

    return 0;
}