#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item, Node *);
static void CopyToItem(Node *, Item *);

/*初始化一个队列*/
void InitializeQueue(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
    pq->len = 0;
}

/*检测队列是否已满*/
bool QueueIsFull(Queue * pq)
{
    return pq->len >= MAXQUEUE;
}

/*检测队列是否为空*/
bool QueueIsEmpty(Queue * pq)
{
    if(pq->front == NULL && pq->rear == NULL && pq->len == 0)
        return true;
    else
        return false;
}

/*返回队列项目数*/
unsigned int QueueItemCount(Queue * pq)
{
    return pq->len;
}

/*向队列尾部添加项目*/
bool EnQueue(Item item, Queue * pq)
{
    Node * pnode;

    if(QueueIsFull(pq))    /*队列已满*/
        return false;
    else
    {
        pnode = (Node *)malloc(sizeof(Node));
        if(pnode == NULL)   /*分配内存失败*/
            return false;
        CopyToNode(item, pnode);
        pnode->next = NULL;
        if(QueueIsEmpty(pq))
        {
            pq->front = pnode;
            pq->rear = pnode;
        }
        else
        {
            pq->rear->next = pnode;
            pq->rear = pnode;
        }
        pq->len++;
        return true;
    }
}

/*将一个项目从首端移出*/
bool DelQueue(Item * pitem, Queue * pq)
{
    Node * pnode;

    if(QueueIsEmpty(pq))
        return false;
    pnode = pq->front;         /*pnode指向首端节点*/
    CopyToItem(pnode, pitem);  /*保存首端的项目*/
    /*处理首端节点*/
    if(pq->len == 1)
    {
        pq->front = NULL;
        pq->rear = NULL;
    }
    else
        pq->front = pnode->next;
    free(pnode);
    pq->len--;
    return true;
}

/*清空队列*/
void FreeQueue(Queue * pq)
{
    Item dummy;
    while(!QueueIsEmpty(pq))
        DelQueue(&dummy, pq);
}

/*将一个项目复制到节点中*/
static void CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}

/*将节点中的项目复制到另一个项目中*/
static void CopyToItem(Node * pnode, Item * pitem)
{
    *pitem = pnode->item;
}
