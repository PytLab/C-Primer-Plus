/*文件复制*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 101
void cpfile(char *, char *);

int main(int argc, char * argv[])
{
    char * source;
    char * target;  /*源文件名, 目标文件名*/

    if(argc != 3)
    {
        printf("Usage: %s source target\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source = argv[1];
    target = argv[2];
    cpfile(source, target);

    return 0;
}

void cpfile(char * source, char * target)
{
    char line[MAXSIZE];
    FILE * in;
    FILE * out;  /*源文件和目标文件的文件指针*/

    in = fopen(source, "rb");
    out = fopen(target, "wb");

    while(fgets(line, MAXSIZE, in) != NULL)
        fputs(line, out);

    fclose(in);
    fclose(out);
}