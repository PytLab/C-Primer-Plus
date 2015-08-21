#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#define LEN 11

void pick(int *, int, int);

int main(void)
{
    int a[LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int pick_times;

    puts("Enter pick times: ");
    while(scanf("%d", &pick_times) == 1)
    {
        puts("Numbers: ");
        pick(a, LEN, pick_times);
        puts("Enter again:");
    }

    return 0;
}

void pick(int * array, int len, int pick_times)
{
    int pickout[pick_times];     /*存放已选出的数组下标*/
    int i, j, idx;               /*主循环计数,判断重复循环计数,随机坐标*/
    bool chosen;

    /*随机抽取不重复的下标并存储在数组中*/
    srand((unsigned int) time(0));
    for(i = 0, chosen = false; i < pick_times; chosen = false)
    {
        idx = rand() % len;
        for(j = 0; j < i; j++)
        {
            if(pickout[j] ==  idx) /*之前已被选中*/
            {
                chosen = true;
                break;
            }
        }
        if(chosen)
            continue;
        else
        {
            pickout[i] = idx;
            i++;
        }
    }

    /*输出选出的数*/
    for(i = 0; i < pick_times; i++)
        printf("%d ", array[pickout[i]]);
    putchar('\n');
}
