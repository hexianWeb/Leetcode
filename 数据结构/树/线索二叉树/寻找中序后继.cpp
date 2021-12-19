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

// 寻找中序后继
ThreadNode *FirstNode(ThreadNode *p)
{
    while (p->ltag == 0)
    {
        /* code */
        p = p->lchild;
    }
    return p;
}
ThreadNode *Nextnode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        /* code */
        return FirstNode(p->rchild);
    }
    else
    {
        return p->rchild;
    }
}
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = FirstNode(T); p != NULL; p = Nextnode(p))
    {
        /* code */
        printf("中序后继为%d", p->data);
    }
}
// 主题函数
int main()
{
}