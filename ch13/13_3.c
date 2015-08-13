#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXSIZE 101
void cpfile(char *, char *);

int main(void)
{
    char source[MAXSIZE];
    char target[MAXSIZE];

    puts("Enter source file name and target file name:");
    scanf("%s%s", source, target);
    cpfile(source, target);

    return 0;
}

void cpfile(char * source, char * target)
{
    FILE * in;
    FILE * out;
    char ch, upperch;

    if((in = fopen(source, "r")) == NULL)
    {
        printf("Can't open %s\n", source);
        exit(EXIT_FAILURE);
    }
    if((out = fopen(target, "w")) == NULL)
    {
        printf("Can't open %s\n", target);
        exit(EXIT_FAILURE);
    }

    /*将小写字母转换成大写*/
    while((ch = getc(in)) != EOF)
    {
        if(isalpha(ch))
        {
            upperch = toupper(ch);
            putc(upperch, out);
        }
        else
            putc(ch, out);
    }

    fclose(in);
    fclose(out);
}