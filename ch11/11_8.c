#include <stdio.h>
#include <string.h>
#define MAXSIZE 21

char * reverse(char *, char *);

int main(void)
{
    char s[MAXSIZE], rs[MAXSIZE];

    puts("Enter a string: ");
    gets(s);
    do
    {
        printf("reverse string: %s\n", reverse(s, rs));
        puts("Enter another a string: ");
        gets(s);
    }while(strcmp(s, "QUIT"));

    return 0;
}

/*反向输出字符串*/
char * reverse(char * s, char * rs)
{
    static char * rstart;  // 反向字符串的首字符的指针
    int i;

    rs[MAXSIZE-1] = '\0';
    for(i = 0; s[i] != '\0'; i++)
        rs[MAXSIZE-2-i] = s[i];
    rstart = rs + (MAXSIZE - 1 - i);

    return rstart;
}
