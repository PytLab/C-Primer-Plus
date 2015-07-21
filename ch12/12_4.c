#include <stdio.h>

int showcall(void);

static int ct = 0; /*全局变量记录函数被调用次数*/

int main(void)
{
    int i;
    for(i = 0; i < 15; i++)
        printf("Fucntion showcall() has been called %d times.\n", showcall());

    return 0;
}

int showcall(void)
{
    return ++ct;
}
