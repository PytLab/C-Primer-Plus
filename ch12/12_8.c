#include <stdio.h>

int * make_array(int elem, int val);
void show_array(const int * ar, int n);

int main(void)
{
    int * pa;
    int size;
    int value;

    puts("Enter the number of element: ");
    scanf("%d", &size);
    while(size > 0)
    {
        puts("Enter the initial value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if(pa) /*分配成功*/
        {
            show_array(pa, size);
            free(pa);
        }
        puts("Enter the number of elements(<1 to quit): ");
        scanf("%d", &size);
    }

    return 0;
}

/*创建指定大小的数组, 并将每一个元组赋予给予的值*/
int * make_array(int elem, int val)
{
    int * pt;
    int i;

    pt = (int *)malloc(elem*sizeof(int)); /*main()中释放*/
    if(pt)
    {
        for(i = 0; i < elem; i++)
            *(pt + i) = val;
        return pt;
    }
    else
    {
        puts("Memery allocation failed.");
        return NULL;
    }
}

void show_array(const int * ar, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("%3d", ar[i]);
        if((i+1) % 8 == 0)
            putchar('\n');
    }
    putchar('\n');
}
