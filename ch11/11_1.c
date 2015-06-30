#include <stdio.h>
#define MAX 20

int main(void)
{
    char string[MAX];
    void get_string(char *);
    void putstring(char *, int);
    
    get_string(string);
    putstring(string, 10);

    return 0;
}

void get_string(char * string)
{
    int i;
    char ch;

    puts("Enter 10 charactors: ");

    for(i = 0; i < 10; i++)
    {
        ch = getchar();
        string[i] = ch;
    }
}

void putstring(char * string, int n)
{
    int i;
    char ch;

    for(i = 0; i < n; i++)
    {
        ch = string[i];
        if(ch == '\n')
            printf("\\n ");
        else if(ch == '\t')
            printf("\\t ");
        else
            printf("%c ", ch);
    }
    putchar('\n');
}