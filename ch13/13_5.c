#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024
#define SLEN 81

void append(FILE *, FILE *);

int main(int argc, char ** argv)
{
    FILE * fa, * fs;
    char * file_app, * file_src;
    int i; /*循环计数*/

    if(argc < 3)
    {
        fprintf(stderr, "Usage %s append-file file1 file2...\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    /*打开目标文件*/
    file_app = argv[1];
    if((fa = fopen(file_app, "a")) == NULL)
    {
        fprintf(stderr, "Can't open %s", file_app);
        exit(EXIT_FAILURE);
    }
    /*为目标文件创建缓冲区*/
    if(setvbuf(fa, NULL, _IOFBF, BUFFSIZE) != 0)
    {
        fprintf(stderr, "Can't create buffer for %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    /*循环进行文件添加*/
    for(i = 2; i < argc; i++)
    {
        file_src = argv[i];
        if(strcmp(file_app, file_src) == 0)
            continue;
        /*打开源文件*/
        if((fs = fopen(file_src, "r")) == NULL)
        {
            fprintf(stderr, "Can't open %s", file_src);
            exit(EXIT_FAILURE);
        }
        /*为源文件创建缓冲区*/
        if(setvbuf(fs, NULL, _IOFBF, BUFFSIZE) != 0)
        {
            fprintf(stderr, "Can't create buffer for %s\n", file_src);
            exit(EXIT_FAILURE);
        }
        /*追加文件内容*/
        append(fa, fs);
        fclose(fs);
        printf("%s appended.\n", file_src);
    }
    fclose(fa);

    return 0;
}

void append(FILE * fa, FILE * fs)
{
    size_t bytes;  /*一次读取的字节数*/
    static const char temp[BUFFSIZE];

    while((bytes = fread(temp, sizeof(char), BUFFSIZE, fs)) > 0)
        fwrite(temp, sizeof(char), bytes, fa);
}
