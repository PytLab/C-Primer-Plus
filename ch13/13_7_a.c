#include <stdio.h>
#include <stdlib.h>
#define SLEN 101

int main(int argc, char * argv[])
{
    char * f1, * f2;
    FILE * fp1, * fp2;
    char line1[SLEN], line2[SLEN];
    void * pt1, * pt2;

    if(argc != 3)
    {
        printf("Usage: %s file1 file2\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    f1 = argv[1];
    f2 = argv[2];
    if((fp1 = fopen(f1, "r")) == NULL)
    {
        printf("Can't open %s\n", f1);
        exit(EXIT_FAILURE);
    }
    if((fp2 = fopen(f2, "r")) == NULL)
    {
        printf("Can't open %s\n", f2);
        exit(EXIT_FAILURE);
    }

    pt1 = fgets(line1, SLEN, fp1);
    pt2 = fgets(line2, SLEN, fp2);
    while(pt1 || pt2)
    {
        fputs(line1, stdout);
        fputs(line2, stdout);
        pt1 = fgets(line1, SLEN, fp1);
        pt2 = fgets(line2, SLEN, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}