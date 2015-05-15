#include <stdio.h>
#define SIZE 255

int main(void)
{
    int count = 0;
    char line[SIZE];
    char ch;           //存放临时字符

    puts("Enter a sentence(less than 255 charactors): ");
    while(scanf("%c", &ch) == 1 && ch != '\n')
    {
        line[count] = ch;
        count++;
    }

    /*反向打印该行*/
    for(count--; count >= 0; count--)
        printf("%c", line[count]);
    putchar('\n');

    return 0;
}