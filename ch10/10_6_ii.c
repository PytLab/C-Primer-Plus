#include <stdio.h>
#define N 5

/*使用指针操作数组*/
int main(void)
{
    double source[2][5] = 
    {
        {1.1, 2.2, 3.3, 4.4, 5.5},
        {6.6, 7.7, 8.8, 9.9, 10.1}
    };
    double target[2][5];

    /*函数原型声明*/
    void copy_arr(const double (*)[N], double (*)[N], int row_num);
    void print_arr(const double (*)[N], int row_num);
    
    copy_arr(source, target, 2);
    puts("source array: ");
    print_arr(source, 2);
    puts("target array: ");
    print_arr(target, 2);

    return 0;
}

void copy_arr(const double (* source)[N], double (* target)[N], int row_num)
{
    //复制整个二维数组
    int row;
    void copy_row(const double *, double *, int);

    for(row = 0; row < row_num; row++)
    {
        double * source_ptr;
        double * target_ptr;

        source_ptr = (double *)(source + row);
        target_ptr = (double *)(target + row);
        copy_row(source_ptr, target_ptr, N);
    }
}

void copy_row(const double * source, double * target, int n)
{
    //复制数组行
    int i;
    for(i = 0; i < n; i++)
        *(target + i) = *(source + i);
}

void print_arr(const double (* arr)[N], int row_num)
{
    int row, col;
    double (* row_ptr)[N];
    double * col_ptr;

    for(row = 0, row_ptr = arr; row < row_num; row++, row_ptr++)
    {
        for(col = 0, col_ptr = (double *)row_ptr; col < N; col++, col_ptr++)
            printf("%-5.1lf", *col_ptr);
        putchar('\n');
    }
}