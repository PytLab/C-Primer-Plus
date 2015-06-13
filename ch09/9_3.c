#include <stdio.h>

int main(void)
{
    char ch;
    int ch_num, row_num;  //每行字符个数, 行数
    void chline(char, int, int);

    puts("Enter a charactor: ");
    scanf("%c", &ch);
    printf("row number: ");
    scanf("%d", &row_num);
    printf("char number: ");
    scanf("%d", &ch_num);

    chline(ch, ch_num, row_num);

    return 0;
}

void chline(char ch, int ch_num, int row_num)
{
    int i, j;
    for(i = 0; i < row_num; i++)
    {
        for(j = 0; j < ch_num; j++)
            putchar(ch);
        putchar('\n');
    }
}