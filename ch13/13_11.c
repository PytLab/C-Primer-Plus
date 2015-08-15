#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SLEN 101

int main(int argc, char * argv[])
{
    char * file, * find;
    char line[SLEN];
    FILE * fp;

    find = argv[1];
    file = argv[2];
    if((fp = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    while((fgets(line, SLEN, fp)) != NULL)
    {
        if(strstr(line, find))
            fputs(line, stdout);
    }
    fclose(fp);

    return 0;
}