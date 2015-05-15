#include <stdio.h>

int main(void)
{
    int count = 0, array[8];

    puts("Enter 8 integers: ");

    /*将整数存入数组*/
    for(count = 0; count <= 7; count++)
    {
        printf("integer %d: ", count + 1);
        scanf("%d", &array[count]);
    }
    
    /*将数组倒序输出*/
    for(count = 7; count >= 0; count--)
        printf("%d ", array[count]);
    putchar('\n');

    return 0;
}