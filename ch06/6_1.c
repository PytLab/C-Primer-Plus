#include <stdio.h>

int main(void)
{
    char alphabet[26];                         //初始化数组
    char character = 'a';
    int count;

    for(count = 0; count < 26; count++)        //存储26小写字母
        alphabet[count] = character + count;

    for(count = 0; count < 26; count++)        //显示小写字母
        putchar(alphabet[count]);
    putchar('\n');

    return 0;
}