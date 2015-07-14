/*实现strncpy函数*/
#include <stdio.h>
#include <string.h>
#define TARGSIZE 21
#define SOURCESIZE 31

int main(void)
{
    char target[TARGSIZE];
    char source[SOURCESIZE];
    int n;

    void strncp(char *, char *, int);

    puts("Enter the source string(QUIT to quit):");
    gets(source);
    puts("Enter number of charactor(<=20): ");
    scanf("%d", &n);
    do
    {
        strncp(target, source, n);
        printf("source string: %s\n", source);
        printf("target string: %s\n", target);
        puts("Enter another source string(QUIT to quit):");
        gets(source);
        puts("Enter number of charactor(<=20): ");
        scanf("%d", &n);
    }while(strcmp(source, "QUIT"));

    return 0;
}

void strncp(char * target, char * source, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(source[i] != '\0')
            target[i] = source[i];
        else
        {
            target[i] = '\0';
            break;
        }
    }
}
