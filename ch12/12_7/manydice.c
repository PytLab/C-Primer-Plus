#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void)
{
    int sets, sides, dice;
    int i; /*循环计数*/

    puts("Enter the number of sets, enter q to quit.");
    while(scanf("%d", &sets) == 1)
    {
        i++;
        puts("How many sides and how many dice?");
        scanf("%d%d", &sides, &dice);
        srand((unsigned int)time(0)); /*初始化种子*/
        for(i = 1; i <= sets; i++)
        {
            printf("%3d", roll_n_dice(dice, sides));
            if(i % 15 == 0)
                putchar('\n');
        }
        putchar('\n');

        puts("How many sets? Enter q to stop.");
    }

    return 0;
}