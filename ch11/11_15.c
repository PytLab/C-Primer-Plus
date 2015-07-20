#include <stdio.h>
#include <ctype.h>
#define MAXSIZE 101

void show_upper(char *);
void show_lower(char *);

int main(int argc, char * argv[])
{
    char input[MAXSIZE];
    char ch;
    int ct = 0; /*输入计数*/

    /*将输入存入数组*/
    puts("Enter something(ctrl+z to stop): ");
    while((ch = getchar()) != EOF && ct < MAXSIZE)
    {
        input[ct] = ch;
        ct++;
    }
    input[ct] = '\0';

    if(!strcmp(argv[1], "-p"))
        puts(input);
    else if(!strcmp(argv[1], "-u"))
        show_upper(input);
    else if(!strcmp(argv[1], "-l"))
        show_lower(input);

    return 0;
}

void show_lower(char * string)
{
    char ch;

    while(ch = *string)
    {
        if(isupper(ch))
            putchar(ch + 32);
        else
            putchar(ch);
        string++;
    }
}

void show_upper(char * string)
{
    char ch;

    while(ch = *string)
    {
        if(islower(ch))
            putchar(ch - 32);
        else
            putchar(ch);
        string++;
    }
}
