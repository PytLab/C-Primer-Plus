#include <stdio.h>

int main(void)
{
    int count = 0;

    puts("Enter something: ");

    while(getchar() != EOF)
        count++;

    printf("There are %d charactors\n", count);

    return 0;
}