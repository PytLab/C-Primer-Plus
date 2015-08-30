#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HOUR (60)

bool newcustomer(double);
Item customertime(long);


int main(void)
{
    Queue line;
    Item temp;               /*存储临时custmer       */
    int hours;               /*模拟的小时数          */
    int perhour;             /*每小时顾客的平均数    */
    long cycle, cyclelimit;  /*循环计数和循环上界    */
    double min_per_cust;     /*顾客到来的平均时间间隔*/
    long turnaway;           /*因队列已满被拒绝的顾客*/
    long customers;          /*被加入队列的顾客数    */
    long wait_time = 0;      /*首端顾客还剩多少时间  */
    long line_wait = 0;      /*队列累计等待时间      */
    long served = 0;         /*服务过的顾客数目      */
    long sum_line = 0;       /*累计的队列长度        */

    InitializeQueue(&line);     /*初始化队列*/
    srand(time(0));          /*初始化随机种子*/
    puts("Case study: Sigmund Lander's Advice Booth");
    puts("Enter the number if simulation hours: ");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HOUR * hours;
    puts("Enter thr average number of customers per hour: ");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HOUR / perhour;

    for(cycle = 0; cycle < cyclelimit; cycle++)
    {
        /*是否有顾客来*/
        if(newcustomer(min_per_cust))
        {
            if(QueueIsFull(&line))
                turnaway++;
            customers++;
            temp = customertime(cycle);  /*实例化customer*/
            EnQueue(temp, &line);
        }
        /*是否服务完顾客*/
        if(wait_time <= 0 && !QueueIsEmpty(&line))
        {
            DelQueue(&temp, &line);
            wait_time = temp.processtime;
            line_wait += wait_time;
            served++;
        }
        if(wait_time > 0)
            wait_time--;
        sum_line += QueueItemCount(&line);
    }

    if(customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("customers served: %ld\n", served);
        printf("turnaway: %ld\n", turnaway);
        printf("average queue size: %lf\n", 
               (double)sum_line / cyclelimit);
        printf("average line wait time: %ld\n",
               (double)line_wait / served);
    }
    else
        puts("No customer.");
    FreeQueue(&line);
    puts("Bye!");

    return 0;
}

bool newcustomer(double x)
{
    if(rand()*x / RAND_MAX < 1)
        return true;
    else
        return false;
}

Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
