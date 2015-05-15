#include <stdio.h>

int main(void)
{
    int row, col;

    for(row = 1; row <= 5; row++)
    {
        for(col = 1; col <= row; col++)
            putchar('$');
        printf("\n");
    }

    return 0;
}