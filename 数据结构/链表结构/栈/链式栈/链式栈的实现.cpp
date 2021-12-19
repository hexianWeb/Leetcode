#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

// 自定义链表结构
typedef struct SNode
{
    /* data */
    int data;
    struct SNode *next;
} SNode, *SLinkList;
// 初始化
bool InitSLinkList(SLinkList &S)
{
    S = (SNode *)malloc(sizeof(SNode));
    if (S == NULL)
    {
        /* code */
        return false;
    }
    S->next = NULL;
    return true;
}
// 元素入栈
bool Push(SLinkList &S, int x)
{
    SNode *temp, *p;
    p = S;
    temp = (SNode *)malloc(sizeof(SNode));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
    return true;
}
// 元素出栈
bool Pop(SLinkList &S, int &x)
{
    SNode *p, *q;
    p = S;
    if (p->next == NULL)
    {
        /* code */
        return false;
    }
    q = p->next;
    x = q->data;
    p->next = q->next;
    return true;
}
// 展示链表
void showList(SLinkList S)
{
    SNode *temp;
    temp = S;
    while (temp != NULL)
    {
        /* code */
        printf("栈内元素:%d\n", temp->data);
        temp = temp->next;
    }
}
// 主函数
int main()
{
    SLinkList S;
    int x;
    if (InitSLinkList(S))
    {
        /* code */
        printf("初始化成功\n");
    }
    if (Push(S, 5))
    {
        /* code */
        printf("元素入栈成功\n");
    }
    Push(S, 4);
    Push(S, 3);
    Push(S, 2);
    Push(S, 1);
    Pop(S, x);
    printf("Pop出的元素%d\n", x);
    showList(S);
}