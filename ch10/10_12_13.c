/*
本代码分别使用了传统C处理的数组的方法和使用变长数组VLA的方法
故可以同时作为12, 13题的答案。
*/
#include <stdio.h>

void print_arr(int, int, const double[*][*]);
double get_row_avg(const double *, int);
double get_avg(int, int, const double arr[*][*]);
double get_max(const double (*)[5], int);

int main(void)
{
    double arr[3][5];  //分配数组
    int i, j;          // 用于循环计数
    double row_avg;    // 每个数集的平均值
    double avg;        // 整体的平均值
    double max;        // 数组中的最大值

    puts("Enter 5 float numbers: ");
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 5; j++)
            scanf("%lf", &arr[i][j]);
        puts("Enter another 5 float numbers: ");
    }
    
    /*打印输入的数组*/
    puts("Array: ");
    print_arr(3, 5, arr);

    /*计算每个数集的平均值*/
    for(i = 0; i < 3; i++)
    {
        row_avg = get_row_avg(arr[i], 5);
        printf("average of number set %d: %.2lf\n", i+1, row_avg);
    }

    /*计算所有数的平均值*/
    avg = get_avg(3, 5, arr);
    printf("average of all numbers: %.2lf\n", avg);

    /*计算最大值*/
    max = get_max(arr, 3);
    printf("Max number: %lf\n", max);
    
    return 0;
}

/*输出一维数组的平均值*/
double get_row_avg(const double * arr, int n)
{
    double sum, avg;
    int i;

    for(i = 0, sum = 0.0; i < n; i++)
        sum += arr[i];
    avg = sum/(float)n;

    return avg;
}

/*计算所有数的平均值(使用VLA)*/
double get_avg(int m, int n, const double arr[m][n])
{
    int i, j;
    double sum, avg;

    for(i = 0, sum = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            sum += arr[i][j];
    }
    avg = sum/(float)(m*n);

    return avg;
}

/*得到数组中最大的值(不使用VLA)*/
double get_max(const double arr[][5], int n)
{
    int i, j;
    double max;

    for(i = 0, max = arr[0][0]; i < n; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(arr[i][j] > max)
                max = arr[i][j];
        }
    }

    return max;
}

/*使用变长数组打印出整个数组内容(使用VLA)*/
void print_arr(int m, int n, const double arr[m][n])
{
    int i, j;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
            printf("%5.1lf", arr[i][j]);
        putchar('\n');
    }
}