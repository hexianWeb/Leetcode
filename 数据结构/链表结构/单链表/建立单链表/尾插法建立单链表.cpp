#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

typedef struct LNode
{
    /* data */
    int data;
    struct LNode *next;

} LNode, *LinkList;
// 初始化链表
bool InitList(LinkList &L)
{

    L = (LNode *)malloc(sizeof(LNode));
    if (L = NULL)
    {
        /* code */
        return false;
    }
    L->next = NULL;
    return true;
}
// 指定节点的后插操作
bool InsertNextNode(LNode *p, int e)
{

    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
    {
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
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
// 链表插入操作前置——按位查找
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
        p = p->next;
        j++;
    }
    if (p == NULL)
    {
        printf("p节点为空\n");
        return false;
    }
    return InsertNextNode(p, e);
}
// 删除节点 核心代码
bool DeleteNode(LNode *p)
{
    printf("当前数据%d\n", p->data);
    LNode *temp = p->next;
    p->data = temp->data;
    p->next = temp->next;
    free(temp);
    return true;
}
// 链表删除操作前置——按位删除
bool ListDelete(LinkList &L, int i)
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
        return true;
    }
    return DeleteNode(p);
}
// 尾插法 链表
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 666)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
// 按位序查找
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        /* code */
        return NULL;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        /* code */
        p = p->next;
        j++;
    }
    return p;
}
// 按值查找
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        /* code */
        p = p->next;
    }
    return p;
}
// 求表的长度
int Length(LinkList L)
{
    int len = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
        len++;
    }
    return len;
}
// 展示链表
void showList(LinkList &L)
{
    LNode *p;
    p = L;

    while (p != NULL)
    {
        /* code */
        printf("数据：%d\n", p->data);
        p = p->next;
    }
}
int main()
{
    LinkList L;
    List_TailInsert(L);
    // ListInsert(L, 2, 555);
    // ListDelete(L, 5);
    // printf("查找的数据为：%d\n", GetElem(L, 4)->data);
    printf("表的长度为%d\n", Length(L));
    showList(L);
}