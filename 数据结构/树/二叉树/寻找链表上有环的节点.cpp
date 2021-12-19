#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>        //max 函数
#include <unordered_set> //哈希表头文件

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

LNode getLoopNode(LinkList &L)
{
    if (L == NULL || L->next == NULL || L->next->next == NULL)
    {
        return;
    }

    LNode *slow = L->next;
    LNode *fast = L->next->next;
    while (slow != fast)
    {
        if (slow->next == NULL || fast->next->next == NULL)
        {
            return;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = L->next;
    while (slow != fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return *slow;
}