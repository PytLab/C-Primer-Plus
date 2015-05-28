#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int lowcount = 0, upcount = 0;

    puts("Enter something: ");

    while((ch = getchar()) != EOF)
    {
        if(islower(ch))
            lowcount++;
        else if(isupper(ch))
            upcount++;
    }

    printf("Lower charactor number: %d\n", lowcount);
    printf("Upper charactor number: %d\n", upcount);

    return 0;
}