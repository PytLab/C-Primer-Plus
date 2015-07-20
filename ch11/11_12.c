#include <stdio.h>

int main(int argc, char * argv[])
{
    for(argc--; argc > 0; argc--)
        printf("%s ", argv[argc]);
    putchar('\n');

    return 0;
}