#include <stdio.h>
#include <time.h>
#include "random.h"
#define NUM 10

void print_arr(int * a, int n);
void intsort(int * a, int n);

int main(void)
{
    int i;  /*循环计数*/
    int a[NUM];

    srandint((unsigned int)time(0));  /*初始化一个随机种子*/
    for(i = 0; i < NUM; i++)
        a[i] = randint(NUM);
    printf("%d random int: \n", NUM);
    print_arr(a, NUM);

    intsort(a, NUM); /*对随机数进行排序*/
    puts("Sorted: ");
    print_arr(a, NUM);

    return 0;
}

void print_arr(int * a, int n)
{
    int i;

    printf("[ ");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("]\n");
}

void intsort(int * a, int n)
{
    int top, seek, tmp;

    for(top = 0; top < n-1; top++)
    {
        for(seek = top+1; seek < n; seek++)
        {
            if(a[seek] > a[top])
            {
                tmp = a[top];
                a[top] = a[seek];
                a[seek] = tmp;
            }
        }
    }
}
