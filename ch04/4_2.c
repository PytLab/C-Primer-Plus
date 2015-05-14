#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[20];

    printf("Enter your name: \n");
    scanf("%s", name);

    printf("\"%s\"\n", name);      //在双引号中打印出来
    printf("'%20s'\n", name);      //宽度20个字符的字段内打印名字，并且整个字段在引号内
    printf("'%-20s'\n", name);     //宽度20个字符的字段内打印名字，左端打印名字
    printf("'   %s'\n", name);     //比名字字段宽3个字符打印

    /*用星号实现比字符串字段宽三个字符*/
    int width = strlen(name) + 3;
    printf("'%*s\n'", width, name);

    return 0;
}