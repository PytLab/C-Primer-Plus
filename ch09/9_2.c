#include <stdio.h>

int main(void)
{
    char ch;
    int i, j;  //列数
    void chline(char, int, int);

    puts("Enter a charactor: ");
    scanf("%c", &ch);
    puts("Enter 2 column number: ");
    scanf("%d%d", &i, &j);

    chline(ch, i, j);

    return 0;
}

void chline(char ch, int i, int j)
{
    int count;

    for(count = 1; count < i; count++)
        putchar(' ');
    for(; count <= j; count++)
        putchar(ch);
    putchar('\n');
}
