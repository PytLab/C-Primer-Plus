#include <stdio.h>
#define SIZE 101

int main(void)
{
    int idx = 0, count = 0;
    char ch, str[SIZE];

    puts("Enter a string(less than 100 charactors and ended in '#'): ");

    while((ch = getchar()) != '#')
    {
        if(ch == '.')
        {
            ch = '!';
            count++;
        }
        
        str[idx] = ch;
        idx++;
    }

    str[idx] = '\0';

    puts(str);
    printf("Replace times: %d\n", count);

    return 0;
}