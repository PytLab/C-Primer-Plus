#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*局部函数原型             */
static CopyToNode(Item, Node *);

/*将item内容放入指定节点中 */
static CopyToNode(Item item, Node * pnode)
{
    pnode->item = item;
}

/*接口函数                 */
/*把列表设置为空列表       */
void InitialList(List * plist)
{
    plist->head = NULL;
    plist->tail = NULL;
    plist->size = 0;
}

/*判断链表是否为空         */
bool ListIsEmpty(const List * plist)
{
    if(plist->head == NULL && plist->tail == NULL && plist->size == 0)
        return true;
    else
        return false;
}

/*判断是否还能为链表申请内存空间*/
bool ListIsFull(const List * plist)
{
    Node * pt;

    pt = (Node *)malloc(sizeof(Node));
    if(pt == NULL)
        return true;
    else
    {
        free(pt);
        return false;
    }
}

/*返回链表的长度*/
unsigned int ListItemCount(const List * plist)
{
    return plist->size;
}

/*创建存放项目的节点并添加到列表尾部*/
bool AddItem(Item item, List * plist)
{
    Node * pnode;
    bool empty;        /*用于判断列表是否为空*/

    pnode = (Node *)malloc(sizeof(Node));
    if(pnode == NULL)  /*内存分配失败*/
        return false;  /*退出函数*/
    else
    {
        CopyToNode(item, pnode);
        pnode->next = NULL;
        empty = ListIsEmpty(plist);

        if(empty)
        {
            plist->head = pnode;
            plist->tail = pnode;
        }
        else
        {
            plist->tail->next = pnode;
            plist->tail = pnode;
        }
        plist->size++;  /*长度增长*/
        return true;
    }
}

/*访问每个节点并对他们分别执行pfun指向的函数*/
void Apply(void (* pfun)(Item item), const List * plist)
{
    Node * pnode;

    pnode = plist->head;
    while(pnode != NULL)
    {
        (*pfun)(pnode->item);
        pnode = pnode->next;
    }
}

/*释放由malloc分配的内存*/
/*把列表指针设置为NULL*/
void FreeList(List * plist)
{
    Node * psave, * current;

    current = plist->head;
    while(current != NULL)
    {
        psave = current->next;
        free(current);
        current = psave;
    }
}
