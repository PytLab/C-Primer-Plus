#include <stdio.h>
void putarr(int *);

int main(void)
{
    /*不同方法初始化*/
    int a[] = {0, 1, 2, 3, 4};
    putarr(a);
    int b[5] = {2};
    putarr(b);
    int c[5] = { [2] = 2 }; /*指定初始化项目*/
    putarr(c);
    int d[5] = {0, 1, 2};
    putarr(d);
    return 0;
}

void putarr(int * arr)
{
    int i;
    for(i = 0; i < 5; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}