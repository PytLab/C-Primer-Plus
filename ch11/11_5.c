#include <stdio.h>

int main(void)
{
    char string[21];
    char ch;
    int res;

    int is_within(char, char *);
    
    puts("Enter a string: ");
    gets(string);
    do
    {
        puts("Enter a char: ");
        ch = getchar();
        getchar();
        res = is_within(ch, string);
        if(res)
            printf("%c is in %s\n", ch, string);
        else
            printf("%c is not in %s\n", ch, string);
        puts("Enter another char: ");
        ch = getchar();
        getchar();
    }while(ch != EOF);

    return 0;
}

int is_within(char ch, char * string)
{
    int i = 0;
    while(string[i] != '\0')
    {
        if(string[i] == ch)
            return 1;
        else
            ++i;
    }
    return 0;
}
