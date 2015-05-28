#include <stdio.h>

int main(void)
{
    char ch;
    int count = 1;

    puts("Enter something: ");

    while((ch = getchar()) != EOF)
    {
        switch(ch)
        {
            case '\n': printf("%s--%d ", "\\n", ch);
                       break;
            case '\t': printf("%s--%d ", "\\t", ch);
                       break;
            default: printf("%c--%d ", ch, ch);
        }
        if(count % 10 == 0)
            putchar('\n');
        count++;
    }

    return 0;
}