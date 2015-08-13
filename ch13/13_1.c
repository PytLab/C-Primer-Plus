#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 21

int main(void)
{
    char file[MAXSIZE];
    FILE * fp;
    char ch;
    long count = 0;

    puts("Enter file name: ");
    gets(file);

    if((fp = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(fp)) != EOF)
    {
        putchar(ch);
        count++;
    }
    putchar('\n');
    fclose(fp);
    printf("File %s has %ld characters.\n", file, count);

    return 0;
}