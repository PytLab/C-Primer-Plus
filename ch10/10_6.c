#include <stdio.h>
#define N 5

int main(void)
{
    double source[2][5] = 
    {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.1}
    };
    double target[2][5];

    /*函数原型声明*/
    void copy_arr(double source[][N], double target[][N], int row_num);
    void print_arr(double arr[][N], int row_num);
    
    copy_arr(source, target, 2);
    puts("source array: ");
    print_arr(source, 2);
    puts("target array: ");
    print_arr(target, 2);

    return 0;
}

void copy_arr(double source[][N], double target[][N], int row_num)
{
    //复制整个二维数组
    int row;
    void copy_row(double source[], double target[], int col_num);

    for(row = 0; row < row_num; row++)
        copy_row(source[row], target[row], N);
}

void copy_row(double source[], double target[], int n)
{
    //复制数组行
    int i;
    for(i = 0; i < n; i++)
        target[i] = source[i];
}

void print_arr(double arr[][N], int row_num)
{
    int row, col;
    for(row = 0; row < row_num; row++)
    {
        for(col = 0; col < N; col++)
            printf("%-5.1lf", arr[row][col]);
        putchar('\n');
    }
}