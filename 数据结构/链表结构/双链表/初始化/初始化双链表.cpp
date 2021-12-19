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