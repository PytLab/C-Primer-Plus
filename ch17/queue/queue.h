#ifndef QUEUE_H_
#define QUEUE_H_

/*决定使用哪种结构的Item*/
#define MALL
/*#define TEST*/

#include <stdbool.h>

#ifdef TEST
typedef int Item;
#endif

#ifdef MALL
struct customer{
    long arrive;
    int processtime;
};
typedef struct customer Item;
#endif

#define MAXQUEUE 10

struct node{
    Item item;
    struct node * next;
};
typedef struct node Node;

struct queue{
    Node * front;      /*指向队列首的指针*/
    Node * rear;       /*指向队列尾的指针*/
    unsigned int len;  /*队列中的项目数*/
};
typedef struct queue Queue;

/*接口函数原型                       */

/*操作: 初始化队列                   */
/*操作前: pq指向一个队列             */
/*操作后: 该队列被初始化为空队列     */
void InitializeQueue(Queue *);

/*操作: 检查队列是否已满             */
/*操作前: pq指向一个队列             */
/*操作后: 如果队列已满返回true       */
/*        否则false                  */
bool QueueIsFull(Queue *);

/*操作: 检测队列是否为空             */
/*操作前: pq指向一个队列             */
/*操作后: 如果队列为空返回true       */
/*        否则false                  */
bool QueueIsEmpty(Queue *);

/*操作: 确定队列项目的个数           */
/*操作前: pq指向一个队列             */
/*操作后: 返回该队列项目个数         */
unsigned int QueueItemCount(Queue *);

/*操作: 向队列尾端添加项目           */
/*操作前: pq指向一个队列
          item是要添加的项目         */
/*操作后: 如果队列未满, item被添加到尾部
          否则不改变队列并返回false  */
bool EnQueue(Item, Queue *);

/*操作: 从队列首端删除项目           */
/*操作前: pq指向一个队列             */
/*操作后: 如果队列非空, 队列首端的   */
/*        项目被复制到*pitem, 并从队 */
/*        列中删除如果删除后队列为空 */
/*        则重置队列,                */
/*        如果队列本身为空，         */
/*        直接返回false              */
bool DelQueue(Item *, Queue *);

/*操作: 清空队列                     */
/*操作前: pq指向一个队列             */
/*操作后: 队列被清空                 */
void FreeQueue(Queue *);

#endif