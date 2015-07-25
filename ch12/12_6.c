#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int stat[10] = {0};
    int seedc, randc; /*种子计数, 随机数计数*/
    int randn; /*获取的1~10之间的随机数*/
    int i; /*输出计数*/

    for(seedc = 0; seedc < 10; seedc++)
    {
        srand((unsigned int)time(0)); /*初始化随机种子*/
        for(randc = 0; randc < 1000000; randc++)
        {
            randn = rand() % 10 + 1;
            stat[randn-1]++; /*进行一次计数*/
        }

    }

    /*输出计数结果*/
    for(i = 0; i < 10; i++)
        printf("%2d: %d\n", i+1, stat[i]);

    return 0;
}