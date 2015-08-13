#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int i;
    char * file;
    FILE * fp;
    char line[101];

    for(i = 1; i < argc; i++)
    {
        file = argv[i];
        printf("%s:\n", file);
        if((fp = fopen(file, "rb")) == NULL)
        {
            printf("Can't open %s\n", file);
            exit(EXIT_FAILURE);
        }
        while(fgets(line, 101, fp) != NULL)
            fputs(line, stdout);
        printf("\n\n");
    }
    fclose(fp);

    return 0;
}