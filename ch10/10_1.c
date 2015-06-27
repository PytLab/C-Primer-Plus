/* rain.c  -- finds yearly totals, yearly average, and monthly
                 average for several years of rainfall data */
#include <stdio.h>
#define MONTHS 12    // number of months in a year
#define YEARS   5    // number of years of data
int main(void)
{
    // initializing rainfall data for 2000 - 2004
    const float rain[YEARS][MONTHS] =
    {
        {4.3, 4.3, 4.3, 3.0, 2.0, 1.2, 0.2, 0.2, 0.4, 2.4, 3.5, 6.6},
        {8.5, 8.2, 1.2, 1.6, 2.4, 0.0, 5.2, 0.9, 0.3, 0.9, 1.4, 7.3},
        {9.1, 8.5, 6.7, 4.3, 2.1, 0.8, 0.2, 0.2, 1.1, 2.3, 6.1, 8.4},
        {7.2, 9.9, 8.4, 3.3, 1.2, 0.8, 0.4, 0.0, 0.6, 1.7, 4.3, 6.2},
        {7.6, 5.6, 3.8, 2.8, 3.8, 0.2, 0.0, 0.0, 0.0, 1.3, 2.6, 5.2}
    };
    int year, month;
    float subtot, total;
    float (* row_pt) [MONTHS];  // 指向数组的指针
    float * col_pt;  // 指向浮点数的指针

    printf(" YEAR    RAINFALL  (inches)\n");
    for (year = 0, total = 0, row_pt = rain; year < YEARS; year++, row_pt++)
    {
        // for each year, sum rainfall for each month
        // 使用指针代替数组下标进行计算
        for (month = 0, subtot = 0, col_pt = (float *)row_pt; month < MONTHS; month++, col_pt++)
            subtot += *col_pt;

        printf("%5d %15.1f\n", 2000 + year, subtot);
        total += subtot; // total for all years 
     }
    printf("\nThe yearly average is %.1f inches.\n\n",
            total/YEARS);
    printf("MONTHLY AVERAGES:\n\n");
    printf(" Jan  Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Oct ");
    printf(" Nov  Dec\n");

    for (month = 0; month < MONTHS; month++)
    {   // for each month, sum rainfall over years
        // 使用指针代替数组下标进行计算
        for(year = 0, subtot = 0, row_pt = rain; year < YEARS; year++, row_pt++)
        {
            col_pt = (float *)row_pt + month;
            subtot += *col_pt;
        }
        printf("%4.1f ", subtot/YEARS);
    }
    printf("\n");
 
    return 0;
}
