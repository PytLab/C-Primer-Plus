#ifndef LIST_H_
#define LIST_H_

#define TSIZE 45  /*存放片名的数组大小*/

struct film{
    char title[TSIZE];
    int rating;
};
typedef struct film Item;

/*链表节点*/
struct node{
    Item item;
    struct node * next;
};
typedef struct node Node;

/*链表定义*/
struct list{
    Node * head;
    Node * tail;
    int size;
};
typedef struct list List;

/*函数原型                                    */
/*操作: 初始化一个链表                        */
/*操作前: plist指向一个列表                   */
/*操作后: 该列表被初始化为空列表              */
void InitialList(List *);

/*操作: 确定链表是否为空                      */
/*操作前: plist指向一个已初始化的列表         */
/*操作后: 如果列表为空返回true, 否则返回false */
bool ListIsEmpty(const List *);

/*操作: 确定链表是否已满                      */
/*操作前: plist指向一个已初始化的列表         */
/*操作后: 如果列表已满返回true, 否则返回false */
bool ListIsFull(const List *);

/*操作: 确定列表中项目的个数*/
unsigned int ListItemCount(const List *);

/*创建存放项目的节点并添加到列表尾部          */
bool AddItem(Item, List *);

/*访问每个节点并对他们分别执行pfun指向的函数  */
void Apply(void (*)(Item item), const List *);

/*释放由malloc分配的内存 */
/*把列表指针设置为NULL   */
void FreeList(List *);

#endif