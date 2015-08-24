#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue line;
    Item temp;    /*存放临时item*/
    char choice;  /*用户的选择*/

    InitializeQueue(&line);  /*初始化队列*/

    puts("Testing the Queue interface. Type a to add a value,");
    puts("type d to delete a value, and type q to quit.");

    while((choice = getchar()) != 'q')
    {
        if(choice == 'a')  /*添加项目*/
        {
            if(QueueIsFull(&line))
                puts("Queue is full.");
            puts("Enter the number: ");
            while(scanf("%d", &temp) != 1)
                puts("Please enter an integer:");
            EnQueue(temp, &line);
            printf("Putting %d into queue.\n", temp);
            while(getchar() != '\n')
                continue;
        }
        else if(choice == 'd')
        {
            if(QueueIsEmpty(&line))
                puts("Queue is empty.");
            DelQueue(&temp, &line);
            printf("Removing %d from queue.\n", temp);
        }
        else
        {
            puts("Enter a or d please.");
            continue;
        }
        /*输出当前状态*/
        printf("%d items in queue\n", QueueItemCount(&line));
        puts("Type a to add, d to delete, q to quit: ");
    }
    FreeQueue(&line);
    puts("Bye!");

    return 0;
}
