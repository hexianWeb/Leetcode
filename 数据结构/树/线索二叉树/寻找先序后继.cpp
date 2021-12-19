#include <stdlib.h>
#include <stdio.h>

// 定义线索二叉树结构体
typedef struct ThreadNode
{
    /* data */
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;

} ThreadNode, *ThreadTree;

// 寻找子树的最左节点
ThreadNode *FirstNode(ThreadNode *temp)
{
    while (temp->ltag == 0)
    {
        /* code */
        temp = temp->lchild;
    }
    return temp;
}
// 寻找先序后继 核心代码
ThreadNode *NextNode(ThreadNode *goal)
{
    if (goal->rtag == 1)
    {
        return goal->rchild;
        /* code */
    }
    else
    {
        if (goal->lchild != NULL)
        {
            /* code */
            return goal->lchild;
        }
        if (goal->rchild != NULL)
        {
            /* code */
            return goal->rchild;
        }
    }
}