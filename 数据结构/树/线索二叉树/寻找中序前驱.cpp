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

// 寻找中序前驱
ThreadNode *LastNode(ThreadNode *p)
{
    while (p->rtag == 0)
    {
        /* code */
        p = p->rchild;
    }
    return p;
}
ThreadNode *PreNode(ThreadNode *p)
{
    if (p->rtag == 0)
    {
        /* code */
        return LastNode(p->lchild);
    }
    else
    {
        return p->rchild;
    }
}
// 非核心代码
void InOrder(ThreadNode *T)
{
    for (ThreadNode *p = LastNode(T); p != NULL; p = PreNode(p))
    {
        /* code */
        printf("中序后继为%d", p->data);
    }
}
// 主题函数
int main()
{
}