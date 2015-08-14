#include <stdio.h>
#include <stdlib.h>
#define MAX 21

int main(void)
{
    long pos;
    char file[MAX];
    FILE * fp;
    char ch;

    fputs("Enter file name: \n", stdout);
    gets(file);

    if((fp = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    /*进行文件定位输出*/
    puts("Enter a position number: ");
    while(scanf("%ld", &pos) == 1)
    {
        fseek(fp, pos, SEEK_SET);  /*定位到指定位置*/
        while((ch = getc(fp)) != '\n')
            putchar(ch);
        putchar('\n');
        puts("Enter another position number: ");
    }

    fclose(fp);

    return 0;
}