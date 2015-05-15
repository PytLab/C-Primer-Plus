#include <stdio.h>
#include <math.h>

int main(void)
{
    const int size = 8;
    int arr[size], count;

    /*设置数组的值*/
    for(count = 0; count <= size - 1; count++)
        arr[count] = pow(2, count);

    /*使用do while 输出数组中的值*/
    count = 0;
    do
        printf("%d ", arr[count]);
    while(++count <= size - 1);
    putchar('\n');

    return 0;
}