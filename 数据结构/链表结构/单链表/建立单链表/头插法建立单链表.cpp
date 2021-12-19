
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
    if (L == NULL)
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
// 链表操作
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

// 链表 头插法
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while (x != 999)
    {
        /* code */
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
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
// 删除核心代码
bool DeleteNode(LNode *p)
{
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}
//按位序删除
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
        return false;
    }
    if (p->next == NULL)
    {
        /* code */
        return false;
    }
    DeleteNode(p);
}

int main()
{
    LinkList L;
    List_HeadInsert(L);
    // ListInsert(L, 2, 555);1
    if (ListDelete(L, 3))
    {
        printf("删除成功\n");
    }
    else
    {
        printf("删除失败");
    }

    showList(L);
}