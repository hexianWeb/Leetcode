#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

typedef struct DNode
{
    /* data */
    int data;
    struct DNode *prior, *next;
} DNode, *DLinklist;
// 初始化双链表
bool InitDlinkList(DLinklist &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        /* code */
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}
// 在p节点之后插入s节点
bool InsertNextDNode(DNode *p, DNode *temp)
{
    if (p == NULL || temp == NULL)
    {
        /* code */
        return false;
    }
    temp->next = p->next;
    temp->prior = p;
    if (p->next != NULL)
    {
        /* code */
        p->next->prior = temp;
    }
    p->next = temp;
    return true;
}
// 删除p节点的后继结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        /* code */
        return false;
    }
    DNode *q = p->next;
    if (q == NULL)
    {
        /* code */
        return false;
    }
    // 如果q节点没有后继节点 仍然会指向NULL
    p->next = q->next;
    if (q->next != NULL)
    {
        /* code */
        q->next->prior = p;
    }
    free(q);
    return true;
}
// 销毁所有链表
bool DeatoryList(DLinklist &L)
{
    while (L->next != NULL)
    {
        /* code */
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
}
// 后向遍历
void showDlist(DLinklist &L)
{
    DNode *p;
    p = L;
    while (p != NULL)
    {
        /* code */
        printf("%d", p->data);
        p = p->next;
    }
}

int main()
{
    printf("程序开始运行\n");
}