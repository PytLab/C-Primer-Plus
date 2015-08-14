#include <stdio.h>
#include <stdlib.h>
long count(char, FILE *);

int main(int argc, char * argv[])
{
    int n = 0;    /*字符统计*/
    char ch;
    char * file;  /*保存文件名*/
    int i;        /*打开文件循环计数*/
    FILE * fp;

    if(argc < 2)
    {
        fprintf(stderr, "Usage %s char (file1 file2...)\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /*读取标准输入文件*/
    else if(argc == 2)
    {
        ch = *argv[1];
        puts("Enter something:");
        n = count(ch, stdin);
        printf("%c has appeared %ld times.\n", ch, n);
    }
    /*依次打开每个文件*/
    else if(argc > 2)
    {
        ch = *argv[1];
        for(i = 2; i < argc; i++)
        {
            file = argv[i];
            if((fp = fopen(file, "r")) == NULL)
            {
                fprintf(stderr, "Can't open %s\n", file);
                continue;
            }
            n = count(ch, fp);
            fprintf(stdout, "%ld %c in file: %s\n", n, ch, file);
            fclose(fp);
        }
    }
    return 0;
}

long count(char ch, FILE * fp)
{
    char tmp;
    long n = 0;

    while((tmp = getc(fp)) != EOF)
    {
        if(tmp == ch)
            n++;
    }

    return n;
}