#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

typedef struct LinkNode
{
    /* data */
    int val;
    LinkNode *next;
    LinkNode(int x) : val(x), next(NULL) {}
} LinkNode, *LinkList;
// 尾插法
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *s, *r = L;
    scanf("%d", &x);
    while (x != 666)
    {
        /* code */
        s = (LinkNode *)malloc(sizeof(LinkNode));
        s->val = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}
void deleteNode(LinkNode *node, int goal)
{
    while (node->val != goal)
    {
        node = node->next;
    }
    /* code */
    node->val = node->next->val;
    node->next = node->next->next;
}
int main()
{
    LinkList L;
    List_TailInsert(L);
    deleteNode(L, 5);
    return 0;
}