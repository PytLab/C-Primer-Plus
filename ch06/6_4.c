#include <stdio.h>

int main(void)
{
    char row_char, col_char;  //行字母和列字母
    void print_space(int);    //函数声明
    int space_num;

    for(row_char = 'A'; row_char <= 'E'; row_char++)    //行循环
    {
        /*输出空格*/
        space_num = 'E' - row_char;
        print_space(space_num);

        /*升序输出, 不包含中间字母*/
        for(col_char = 'A'; col_char < row_char; col_char++)
            putchar(col_char);

        /*降序输出, 包含中间字母*/
        for(col_char = row_char; col_char >= 'A'; col_char--)
            putchar(col_char);

        printf("\n");
    }

    return 0;
}

void print_space(int space_num)
{
    int count;
    for(count = 0; count < space_num; count++)
        printf(" ");
}