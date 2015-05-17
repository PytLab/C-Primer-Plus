#include <stdio.h>

int main(void)
{
    int even_num = 0, odd_num = 0;    //偶数和奇数个数
    int even_sum = 0, odd_sum = 0;    //偶数和， 奇数和
    float even_ave, odd_ave;          //偶数和奇数的平均值
    int i;

    puts("Enter integer(enter 0 to quit): ");

    while(scanf("%d", &i) == 1 && i != 0)
    {
        switch(i % 2)
        {
            case 0: even_sum += i;
                    even_num++;
                    break;
            case 1: odd_sum += i;
                    odd_num++;
                    break;
        }

        puts("Enter another integer: ");
    }

    even_ave = (float)even_sum/(float)even_num;  //把总和和数量都转化为浮点数
    odd_ave = (float)odd_sum/(float)odd_num;

    puts("Even number: ");
    printf("number: %d, average: %.2f\n", even_num, even_ave);
    puts("Odd number: ");
    printf("number: %d, average: %.2f\n", odd_num, odd_ave);

    return 0;
}