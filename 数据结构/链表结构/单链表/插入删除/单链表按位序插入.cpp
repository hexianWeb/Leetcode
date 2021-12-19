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
    ListInsert(L, 2, 555);
    showList(L);
    MyLinkedList *obj = new MyLinkedList();
    int param_1 = obj->get(index);
    obj->addAtHead(val);
    obj->addAtTail(val);
    obj->addAtIndex(index, val);
    obj->deleteAtIndex(index);
}