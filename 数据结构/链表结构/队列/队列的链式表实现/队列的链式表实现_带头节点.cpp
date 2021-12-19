#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

// 队列节点结构体
typedef struct LinkNode
{
    /* data */
    int data;
    struct LinkNode *next;
} LinkNode;
// 队列 头尾指针结构体
typedef struct
{
    /* data */
    LinkNode *front, *rear;
} LinkQueue;
// 初始化
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    //空表初始指向空
    Q.rear->next = NULL;
}
// 判断空操作
bool IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        /* code */
        return true;
    }
    return false;
}
bool EnQueue(LinkQueue &Q, int x)
{
    LinkNode *temp = (LinkNode *)malloc(sizeof(LinkNode));
    if (temp == NULL)
    {
        return false;
    }
    temp->data = x;
    temp->next = NULL;
    Q.rear->next = temp;
    Q.rear = temp;
    return true;
}
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == Q.rear)
    {
        /* code */
        printf("此队列为NULL");
    }
    LinkNode *temp = Q.front->next;
    x = temp->data;
    Q.front->next = temp->next;
    if (Q.rear == temp)
    {
        /* code */
        Q.front = Q.rear;
    }
    free(temp);
    return true;
}