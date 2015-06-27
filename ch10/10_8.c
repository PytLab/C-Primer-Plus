#include <stdio.h>

/*使用变长数组进行数组复制*/
int main(void)
{
    double source[3][5] = {
        {4.3, 4.3, 4.3, 3.0, 2.0},
        {8.5, 8.2, 1.2, 1.6, 2.4},
        {9.1, 8.5, 6.7, 4.3, 2.1},
    };
    double target[3][5];

    void copy_vla(int, int, double source[*][*], double target[*][*]);
    void print_arr(int, int, double arr[*][*]);

    copy_vla(3, 5, source, target);
    puts("source array: ");
    print_arr(3, 5, source);
    puts("target array: ");
    print_arr(3, 5, target);

    return 0;
}

void copy_vla(int m, int n, double source[m][n], double target[m][n])
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            target[i][j] = source[i][j];
    }
}

void print_arr(int m, int n, double arr[m][n])
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%5.1lf", arr[i][j]);
        putchar('\n');
    }
}
