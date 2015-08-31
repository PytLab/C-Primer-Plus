#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct pair{
    Node * parent;
    Node * child;
};
typedef struct pair Pair;

/*内部链接函数*/
static Pair SeekItem(const Item *, const Tree *);
static Node * MakeNode(Item *);
static void AddNode(Node *, Node *);
static bool ToLeft(const Item *, const Item *);
static bool ToRight(const Item *, const Item *);
static void DeleteNode(Node **);
static void InOrder(const Node *, void (*)(Item));
static void InOrder2(const Node *, void (*)(Item));
static void InOrder3(const Node *, void (*)(Item));
static void DeleteAllNodes(Node *);

/*初始化一棵树*/
void InitializeTree(Tree * ptree)
{
    ptree->root = NULL;
    ptree->size = 0;
}

/*确定树是否为空*/
bool TreeIsEmpty(const Tree * ptree)
{
    if(ptree->root == NULL && ptree->size == 0)
        return true;
    else
        return false;
}

/*判断树是否已满*/
bool TreeIsFull(const Tree * ptree)
{
    if(ptree->size >= MAXITEM)
        return true;
    else
        return false;
}

/*确定树中的节点总数*/
int TreeItemCount(const Tree * ptree)
{
    return ptree->size;
}

/*将项目添加到树中*/
bool AddItem(Item * pitem, Tree * ptree)
{
    Node * pnew_node;  /*要添加的新节点*/

    /*检查树是否已满*/
    if(TreeIsFull(ptree))
    {
        fputs("Tree is full.\n", stderr);
        return false;
    }
    /*检查项目是否已在树中*/
    if(SeekItem(pitem, ptree).child != NULL)
    {
        fputs("Attempted to add dupicate item.\n", stderr);
        return false;
    }
    /*创建新节点待加入树中*/
    pnew_node = MakeNode(pitem);
    if(pnew_node == NULL)
    {
        fputs("Couldn't create node.", stderr);
        return false;
    }
    /*将新节点加入到树中*/
    if(ptree->root == NULL)
        ptree->root = pnew_node;
    else
        AddNode(pnew_node, ptree->root);
    ptree->size++;
    return true;
}

/*在树中寻找指定item*/
static Pair SeekItem(const Item * pitem, const Tree * ptree)
{
    Pair look = {NULL, ptree->root};  /*初始化目标结构  */
    Pair None = {NULL, NULL};         /*寻找失败的返回值*/

    /*空树的情况*/
    if(look.child == NULL)
        return look;
    while(look.child != NULL)
    {
        if(ToLeft(pitem, look.child))
        {
            look.parent = look.child;
            look.child = look.child->left;
        }
        else if(ToRight(pitem, look.child))
        {
            look.parent = look.child;
            look.child = look.child->right;
        }
        else
            return look;  /*找到相同的item节点*/
    }
    return None;  /*未找到目标节点*/
}

/*判断是否可以将item插入到左子节点*/
static bool ToLeft(const Item * pitem, const Item * pitem_in_node)
{
    int comp;

    comp = strcmp(pitem->petname, pitem_in_node->petname)
    if(comp < 0)
        return true;
    else if(comp == 0 &&
            strcmp(pitem->petkind, pitem_in_node->petkind) < 0)
        return true;
    else
        return false;
}

/*判断是否可以将item插入到右子节点*/
static bool ToRight(const Item * pitem, const Item * pitem_in_node)
{
    int comp;

    comp = strcmp(pitem->petname, pitem_in_node->petname);
    if(comp > 0)
        return true;
    else if(comp == 0 &&
            strcmp(pitem->petkind, pitem_in_node->petkind) > 0)
        return true;
    else
        return false;
}

/*根据item创建新节点*/
static Node * MakeNode(Item * pitem)
{
    Node * pnode;

    pnode = (Node *)malloc(sizeof(Node));
    if(pnode != NULL)
    {
        pnode->left = NULL;
        pnode->right = NULL;
        pnode->item = *pitem;
    }

    return pnode;
}

/*将一个节点加入树中*/
static void AddNode(Node * pnode, Node * root)
{
    if(ToLeft(&(pnode->item), &(root->item))
    {
        if(root->left == NULL)  /*想加的地方为空, 直接加*/
            root->left = pnode;
        else
            AddNode(pnode, root->left);
    }
    else if(ToRight(&(pnode->item), &(root->item))
    {
        if(root->right == NULL)
            root->right = pnode;
        else
            AddNode(pnode, root->right);
    }
}

/*检查指定项目是否在树中*/
bool InTree(Item * pitem, Tree * ptree)
{
    return SeekItem(pitem, ptree).child == NULL ? false : true;
}

/*从树中删除项目*/
bool DeleteItem(Item * pitem, Tree * ptree)
{
    Pair look;

    look = SeekItem(pitem, ptree);

    if(look.child == NULL)  /*未找到指定项目*/
        return false;
    if(look.parent == NULL)  /*在根节点上*/
        DeleteNode(&ptree->root);
    else if(look.child == look.parent->left)
        DeleteNode(&look.parent->left);
    else if(look.child == look.parent->right)
        DeleteNode(&look.parent->right);
    return true;
}

/***********************************************
    Function: DeleteNode()
    Description: 删除树中的指定节点
    Calls: 
    Calsss By: DeleteItem()
    Input: 节点指针的地址,
           即待删除节点中父节点中left或者right的地址
    Output: void
************************************************/
static void DeleteNode(Node ** ptr)
{
    /* *ptr指向待删除的节点 */
    Node * temp;  /*临时存储一个节点指针*/

    if((*ptr)->left == NULL && (*ptr)->right == NULL)
    {   /*叶节点*/
        free(*ptr);
        *ptr = NULL;
    }
    else if((*ptr)->left == NULL)
    {   /*只有左节点为空*/
        temp = *ptr;
        *ptr = (*ptr)->right;
        free(temp);
    }
    else if((*ptr)->right == NULL)
    {   /*只有右节点为空*/
        temp = *ptr;
        *ptr = (*ptr)->left;
        free(temp);
    }
    else
    {   /*左右节点接不为空*/
        /*找到右子节点依附的位置
          依附在左子树最右端*/
        temp = (*ptr)->left;
        /*最终temp->right指向之前的右子树*/
        while(temp->right != NULL)
            temp = temp->right;
        temp->right = (*ptr)->right;

        temp = *ptr;
        /*将左子树接到原有的父节点*/
        *ptr = (*ptr)->left;
        free(temp);
    }
}

/*遍历树*/
void Traverse(Tree * ptree, void (* pfunc)(Item item))
{
    if(ptree->root != NULL)
        InOrder(ptree->root, pfunc);
}

static void InOrder(const Node * root, void (* pfunc)(Item))
{   /*按左子树, 项目, 右子树的顺序*/
    if(root != NULL)
    {
        InOrder(root->left, pfunc);
        (*pfunc)(root->item);
        InOrder(root->right, pfunc);
    }
}

static void InOrder2(const Tree * ptree, void (* pfunc)(Item))
{   /*按项目, 左子树, 右子树顺序*/
    if(root != NULL)
    {
        (*pfunc)(root->item);
        InOrder2(root->left, pfunc);
        InOrder2(root->right, pfunc);
    }
}

static void InOrder3(const Tree * ptree, void (* pfunc)(Item))
{   /*按左子树, 右子树, 项目顺序*/
    if(root != NULL)
    {
        InOrder3(root->left, pfunc);
        InOrder3(root->right, pfunc);
        (*pfunc)(root->item);
    }
}

void DeleteAll(Tree * ptree)
{
    if(ptree->root != NULL)
        DeleteAllNodes(ptree->root)
    ptree->root = NULL;
    ptree->size = 0;
}

static void DeleteAllNodes(Node * root)
{
    Node * pright;

    if(root != NULL)
    {
        pright = root->right;
        DeleteAllNodes(root->left);
        free(root);
        DeleteAllNodes(pright);
    }
}
