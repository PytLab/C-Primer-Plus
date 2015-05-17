#include <stdio.h>

int main(void)
{
    char ch;
    int space_num = 0;    //空格数目
    int newline_num = 0;  //换行符数目
    int other_num = 0;    //其他字符数目

    puts("Enter a string end in '#': ");
    
    while((ch = getchar()) != '#')
    {
        switch(ch)
        {
            case ' ' : space_num++;
                       break;
            case '\n': newline_num++;
                       break;
            default  : other_num++;
                       break;
        }
    }

    printf("Number of space: %d\n", space_num);
    printf("Number of line break: %d\n", newline_num);
    printf("Number of other charactors: %d\n", other_num);

    return 0;
}