#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <iostream>
using namespace std;
// Elemtype数据类型定义
typedef int ElemType;

// 队列节点的结构体定义
typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *next;
};

// 队头、尾 指针结构体定义

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

void Init_LinkQueue(LinkQueue &Q)
{
    Q.front = NULL;
    Q.rear = NULL;
}
void EnQueue(LinkQueue &Q, ElemType x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->next = NULL;
    if (Q.front == NULL) //若当前要插入的节点是第一个节点
    {
        Q.front = s; //则将队列的头尾指针都指向当前新建节点
        Q.rear = s;
    }
    else
    {
        // 照常插入
        Q.rear->next = s;
        Q.rear = s;
    }
}
// 无头结点出队
void DeQueue(LinkQueue &Q, ElemType &x)
{
    if (Q.front == NULL)
    {
        cout << "当前队列为空" << endl;
    }
    LinkNode *p = Q.front;
    x = p->data;       //获取并返还元素
    Q.front = p->next; //头指针后移
    if (Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
}