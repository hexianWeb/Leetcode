#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
// 结构体定义  初始Elemtype为int
typedef struct ThreadNode
{
    /* data */
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;

} ThreadNode, *ThreadTree;
// 定义全局遍历pre为NULL
ThreadNode *pre = NULL;
// 初始化二叉树根节点
void InitThreadTree(ThreadTree T)
{
    pre = NULL;
}
// 中序遍历线索化创建二叉树
void CreateInThread(ThreadTree T)
{
    InitThreadTree(T);
    if (T != NULL)
    {
        /* code */
        InThread(T);
        if (pre->rchild = NULL)
        {
            /* code */
            pre->rtag = 1;
        }
    }
}
// 核心代码
void visit(ThreadNode *q)
{
    if (q->lchild == NULL)
    {
        /* code */
        q->lchild = pre;
        q->ltag = 1;
    }
    if (pre != NULL || q->rchild == NULL)
    {
        /* code */
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;

    return;
}
// 核心代码
void InThread(ThreadTree T)
{

    if (T != NULL)
    {
        /* code */
        visit(T);
        if (T->ltag == 0)
        {
            /* code */ InThread(T->lchild);
        }
        if (T->rtag == 0)
        {
            /* code */
            InThread(T->rchild);
        }
    }
}
// 主题函数
int main()
{
}