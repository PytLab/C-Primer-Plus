#include <stdio.h>

void delspace(char *);

int main(void)
{
    char ch[81];

    puts("Enter a string: ");
    gets(ch);
    while(*ch != '\0')
    {
        printf("Raw string: %s\n", ch);
        delspace(ch);
        printf("Clean string: %s\n", ch);
        puts("Enter another string: ");
        gets(ch);
    }

    return 0;
}

/*去除字符串中的空格*/
void delspace(char * ch)
{
    char * p1;  /*主循环指针*/
    char * p2;  /*前移循环指针*/

    p1 = ch;
    while(*p1 != '\0')
    {
        if(*p1 == ' ')
        {
            /*将此空格后面直到字符串结尾的字符向前移一位*/
            p2 = p1;
            while(*p2 != '\0')
            {
                *p2 = *(p2 + 1);
                p2++;
            }/*前移循环结束*/
        }
        p1++;
    }
}
