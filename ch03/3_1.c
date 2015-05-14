#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    /*测试整数上溢*/
    int int_max = INT_MAX;                   //int类型的最大值
    unsigned uint_max = UINT_MAX;            //unsigned int类型最大值

    printf("int_max: %d\nint_max+1: %d\nint_max+2: %d\n",
           int_max, int_max+1, int_max+2);
    printf("uint_max: %u\nuint_max+1: %u\nuint_max+2: %u\n",
           uint_max, uint_max+1, uint_max+2);

    /*测试浮点数上溢*/
    float float_max = FLT_MAX;               //float类型最大值
    float toobig = float_max*100.0f;

    printf("float_max: %f\n", float_max);
    printf("float_max*100.0f: %f\n", toobig);

    /*测试浮点数下溢*/
    float float_min = 1.234567E-38;
    float toosmall = float_min/10;           //指数部分已达最小，尾数部分右移，精度损失

    printf("float_min: %e\n", float_min);
    printf("float_min/100.0f: %e\n", toosmall);
}