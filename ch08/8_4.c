#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int ch_count = 0, wd_count = 0;
    float ave;

    puts("Enter something: ");

    while((ch = getchar()) != EOF)
    {
        if(ch != ' ' && !ispunct(ch) && !isspace(ch))
            ch_count++;
        else
            wd_count++;
    }

    ave = (float)ch_count / (float)wd_count;
    printf("Average: %.2f\n", ave);

    return 0;
}