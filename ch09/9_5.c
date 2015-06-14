#include <stdio.h>

int main(void)
{
    int a = 10, b = 12;
    void larger_of(int *, int *);

    printf("Before replacement a = %d, b = %d\n", a, b);
    larger_of(&a, &b);
    printf("After replacement a = %d, b = %d\n", a, b);

    return 0;
}

void larger_of(int * pa, int * pb)
{
    int temp;  // 存放较大数值
    temp = *pa > *pb ? *pa: *pb;
    *pa = temp;
    *pb = temp;
}
