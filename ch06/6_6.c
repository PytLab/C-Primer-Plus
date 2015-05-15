#include <stdio.h>
#include <string.h>
#define SIZE 20

int main(void)
{
    char word[SIZE];    //存放单词的字符数组
    int len;            //单词长度
    int count;

    puts("Enter a word: ");
    gets(word);

    /*逆向输出单词*/
    len = strlen(word);
    for(count = len - 1; count >= 0; count--)
        putchar(word[count]);
    putchar('\n');

    return 0;
}