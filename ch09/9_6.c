#include <stdio.h>

int main(void)
{
    char ch;
    int loc;  //字母位置
    int locate(char);

    puts("Enter something(CTRL+Z to quit): ");
    while(scanf("%c", &ch) != EOF)
    {
        loc = locate(ch);
        if(loc == -1)
            printf("%c: not a letter.\n", ch);
        else
            printf("%c: location %d.\n", ch, loc);
    }

    return 0;
}

int locate(char ch)
{
    int location;

    if(ch >= 'a' && ch <= 'z')
        location = ch - 'a' + 1;
    else if(ch >= 'A' && ch <= 'Z')
        location = ch - 'A' + 1;
    else
        location = -1;

    return location;
}
