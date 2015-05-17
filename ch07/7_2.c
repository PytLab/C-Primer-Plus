#include <stdio.h>

int main(void)
{
    char ch;
    int count = 1;

    puts("Enter string end in '#': ");

    while((ch = getchar()) != '#')
    {
        printf("%c/%d ", ch, ch);
        if(count++ % 8 == 0)
            putchar('\n');
    }

    putchar('\n');

    return 0;
}