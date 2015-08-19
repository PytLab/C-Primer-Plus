#include <stdio.h>

char * itobs(int, char *);
void show_bstr(const char *);

int main(void)
{
    int number;
    char bin_str[8*sizeof(int) + 1];  /*存放二进制字符的数组*/

    puts("Enter a integer number: ");
    while(scanf("%d", &number) == 1)
    {
        itobs(number, bin_str);
        printf("%d is: \n", number);
        show_bstr(bin_str);
        putchar('\n');
        number = invert_end(number, 4);
        printf("Inverting the last 4 bits gives: \n");
        show_bstr(itobs(number, bin_str));
        putchar('\n');
    }
    puts("Bye!");

    return 0;
}

char * itobs(int n, char * p)
{
    int i;
    static int size = 8*sizeof(int);

    /*循环通过移位运算获取每一位的值*/
    for(i = size-1; i >= 0; i--, n >>= 1)
        p[i] = ((00000001) & n) + '0';
    p[size] = '\0';

    return p;
}

void show_bstr(const char * p)
{
    int i = 0;
    while(p[i])
    {
        putchar(p[i]);
        if((i + 1)%4 == 0)
            putchar(' ');
        i++;
    }
}

int invert_end(int num, int bits)
{
    int mask = 1;
    /*获取掩码*/
    while(bits-- > 1)
    {
        mask <<= 1;
        mask++;
    }

    return num ^ mask;
}
