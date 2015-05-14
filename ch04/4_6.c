#include <stdio.h>
#include <float.h>

int main(void)
{
    float f = 1.0/3.0;
    double d = 1.0/3.0;

    printf("%.4f\n", f);
    printf("%.12f\n", f);       //超出了float最大有效数字位数
    printf("%.16f\n", f);       //超出了float最大有效数字位数
    printf("%d\n", FLT_DIG);

    /*均未超出double最大有效数字位数*/
    printf("%.4lf\n", d);
    printf("%.12lf\n", d);
    printf("%.16lf\n", d);
    printf("%d\n", DBL_DIG);

    return 0;
}