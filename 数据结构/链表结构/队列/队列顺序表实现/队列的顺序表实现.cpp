#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define Maxsize 10
typedef struct
{
    /* data */
    int data[Maxsize];
    int front, rear; //对头指针和队尾指针
} SqQueue;

// 初始化队列
bool InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    return true;
}
// 判断是否队列为空

bool QueueEmpty(SqQueue Q)
{
    if (Q.rear == Q.front)
    {
        /* code */
        return true;
    }
    return false;
}
// 入队操作
bool EnQueue(SqQueue &Q, int x)
{
    if ((Q.rear + 1) % Maxsize == Q.front)
    {
        /* code */
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    return true;
}
// 出队操作
bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.rear == Q.front)
    {
        /* code */
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % Maxsize;
    return true;
}
// 获得队头元素
bool GetQueue(SqQueue Q, int &x)
{
    if (Q.rear == Q.front)
    {
        /* code */
        return false;
    }
    x = Q.data[Q.front];
    return true;
}
void ShowQueue(SqQueue Q)
{
    // int num = 0;
    while (Q.rear > Q.front)
    {
        /* code */
        printf("%d\n", Q.data[Q.front]);
        Q.front++;
    }
    // printf("%d", Q.data[0]);
}
void Length(SqQueue Q)
{
    printf("当前顺序队列长度为%d", (Q.rear + Maxsize - Q.front) % Maxsize);
}
int main()
{
    SqQueue Q;
    int x;
    if (InitQueue(Q))
    {
        printf("队列初始化成功\n");
    }
    if (EnQueue(Q, 0))
    {
        /* code */
        printf("元素入栈成功\n");
    }
    // 使用了一个空余节点来判断当前是否为空表
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    EnQueue(Q, 7);
    EnQueue(Q, 8);
    EnQueue(Q, 9);
    printf("---------------------------\n");
    ShowQueue(Q);
    Length(Q);
    DeQueue(Q, x);
    printf("出队元素为：%d\n", x);
    ShowQueue(Q);
    Length(Q);
}