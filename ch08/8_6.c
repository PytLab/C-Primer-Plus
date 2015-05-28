#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;      //存放第一个分空白字符
    char get_first(void);

    ch = get_first();

    printf("The first non-blank charator: %c\n", ch);
}

char get_first(void)
{
    char ch;

    puts("Enter something: ");

    while(isspace(ch = getchar()))
        continue;

    return ch;
}