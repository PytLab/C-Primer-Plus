#include <stdio.h>
#include <math.h>

int main(void)
{
    int times;
    double sum1(int);        //函数原型声明
    double sum2(int);
    double sum_1, sum_2;     //求和的结果

    printf("Enter times of operation: ");
    while(scanf("%d", &times) == 1)
    {
        sum_1 = sum1(times);
        sum_2 = sum2(times);

        printf("1.0 + 1.0/2.0 + 1.0/3.0 + ...(%d terms) = %lf\n", times, sum_1);
        printf("1.0 + 1.0/2.0 + 1.0/3.0 - ...(%d terms) = %lf\n", times, sum_2);
        printf("Enter another number: ");
    }
    
    return 0;
}

double sum1(int times)
{
    int count;
    double sum = 0;

    for(count = 1; count <= times; count++)
        sum += 1.0/(double)count;

    return sum;
}

double sum2(int times)
{
    int count;
    double sum = 0;

    for(count = 1; count <= times; count++)
        sum += pow(-1, count + 1)*(1.0/(double)count);

    return sum;
}