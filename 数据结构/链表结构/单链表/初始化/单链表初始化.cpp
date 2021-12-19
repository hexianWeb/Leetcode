#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

typedef struct LNode
{
    int data;
    struct LNode *next;
    /* data */
} LNode, *LinkList;
// 初始化单链表
bool InitList(LinkList &L)
{

    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        /* code */
        return false;
    }
    L->next = NULL;
    return true;
}
// 判断单链表是否为空
bool Empty(LinkList L)
{
    if (L->next == NULL)
    {
        /* code */
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    // LNode *L;
    LinkList L;
    if (InitList(L))
    {
        printf("链表初始化成功\n");
    }
}
