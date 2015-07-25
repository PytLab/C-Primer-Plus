#include <stdio.h>
#include <stdlib.h>

static int rollem(int sides) /*具有内部链接的函数*/
{
    int roll; /*置骰子的结果*/

    roll = rand() % sides + 1;
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int total = 0, d; /*骰子的得到的总数, 骰子计数*/

    if(sides < 2)
    {
        puts("Need at least 2 sides.");
        return -1;
    }

    for(d = 0; d < dice; d++)
        total += rollem(sides);

    return total;
}