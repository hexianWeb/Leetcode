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
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        /* code */
        return false; //头结点存在 不允许小于1
    }
    LNode *p;  //p正在扫描的节点
    int j = 0; //p指向的是第几个节点
    p = L;     //L指向头结点 即第0个节点
    while (p != NULL && j < i - 1)
    {
        /* code */
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
    // return InsertPriorNode(p, e);
}
// 指定节点的前插操作
bool InsertPriorNode(LNode *p, int e)
{
    LNode *temp = (LNode *)malloc(sizeof(LNode));
    if (temp == NULL)
    {
        /* code */
        return false;
    }
    temp->data = p->data;
    temp->next = p->next;
    p->next = temp;
    p->data = e;
    return true;
}
// 指定节点的后插操作
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s = NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    return true;
}
//按位序删除
bool ListDelete(LinkList &L, int i, int e)
{
    if (i < 1)
    {
        /* code */
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        /* code */
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        /* code */
        return false;
    }
    if (p->next == NULL)
    {
        /* code */
        return false;
    }
    DeleteNode(p);
}
// 删除的核心语句
bool DeleteNode(LNode *p)
{
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
int main()
{
    // LNode *L;
    LinkList L;
    if (InitList(L))
    {
        printf("链表初始化成功");
    }
}
// /一般来讲 我们会在定义时设定带头结点的空链表
// struct SinglyListNode
// {
//     int val;
//     SinglyListNode *next;
//     SinglyListNode(int x) : val(x), next(NULL) {}
// };