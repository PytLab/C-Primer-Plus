#ifndef TREE_H_
#define TREE_H_

#define SLEN 20
#define MAXITEM 10   /*树的最大节点数*/
#include <stdbool.h>

/*定义Item结构*/
struct item{
    char petname[SLEN];
    char petkind[SLEN];
};
typedef struct item Item;

/*定义节点结构 */
struct node{
    Item item;
    struct node * left;
    struct node * right;
};
typedef struct node Node;

/*定义树结构*/
struct tree{
    Node * root;  /*指向根节点的指针*/
    int size;    /*树的节点数      */
};
typedef struct tree Tree;

/*函数原型*/
/*-----------------------------           */
/*操作: 把树初始化为空树                  */
/*操作前: ptree指向一棵树                 */
/*操作后: 树被初始化为空树                */
void InitializeTree(Tree *);         
         
/*操作: 确定树是否为空                    */
/*操作前: ptree指向一棵树                 */
/*若树为空返回true, 否则返回false         */
bool TreeIsEmpty(const Tree *);         
         
/*操作: 确定树是否已满                    */
/*操作前: ptree指向一棵树                 */
/*若树大小超出限定大小返回true            */
/*否则返回false                           */
bool TreeIsFull(const Tree *);         
         
/*操作: 确定树中的节点数*/         
int TreeItemCount(const Tree *);         
         
/*操作: 像树中添加项目                    */
/*操作前: ptree指向一棵树,                */
/*        pitem指向一个Item               */
/*操作后: 若item不在树的节点中,           */
/*将item添加到树的相应位置,               */
/*并返回true, 否则返回false               */
bool AddItem(Item *, Tree *);         
         
/*操作: 检查指定项目是否在树中            */
/*操作前: pitem指向一个项目,              */
/*        ptree指向一个树                 */
/*操作后: 若pitem所指向的项目在树         */
/*      中返回true, 否则返沪false         */
bool InTree(Item *, Tree *);

/*操作:   从树中删除一个项目              */
/*操作前: pitem是待删除的项目的地址       */
/*        ptree是指向一个树               */
/*操作后: 如果项目在树中将其删除并返回true*/
/*        否则返沪false                   */
bool DeleteItem(Item *, Tree *);

/*操作: 把一个函数作用于树中的每个项目      */
/*操作前: ptree指向一个初始化的树           */
/*        pfun指向一个没有返回值的函数      */
/*操作后: pfun指向函数被作用于树中的每个项目*/
void Traverse(Tree *, void (*)(Item));

/*操作：从树中删除所有节点　　　　　　　　　*/
/*操作前: ptree指向一个树                   */
/*操作后: 该树为空                          */
void DeleteAll(Tree *);

#endif
