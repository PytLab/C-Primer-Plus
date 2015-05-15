#include <stdio.h>
#define SIZE 8

int main(void)
{
    double array1[SIZE], array2[SIZE];
    int count1, count2;
    double sum;

    /*设置数组的值*/
    puts("Enter 8 float numbers: ");
    for(count1 = 0; count1 <= SIZE - 1; count1++)
    {
        printf("Number %d: ", count1 + 1);
        scanf("%lf", &array1[count1]);
    }

    /*设置第二个数组的值*/
    for(count1 = 0; count1 <= SIZE - 1; count1++)
    {
        for(count2 = 0, sum = 0.0; count2 <= count1; count2++)
            sum += array1[count2];

        array2[count1] = sum;
    }

    /*输出两个数组的值*/
    for(count1 = 0; count1 <= SIZE - 1; count1++)
        printf("%6.2lf ", array1[count1]);
    putchar('\n');

    for(count2 = 0; count2 <= SIZE - 1; count2++)
        printf("%6.2lf ", array2[count2]);
    putchar('\n');
}