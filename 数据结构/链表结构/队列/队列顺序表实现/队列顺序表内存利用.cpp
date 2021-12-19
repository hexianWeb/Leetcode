// 最大化利用开辟空间的内存
#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#define Maxsize 10
typedef struct
{
    /* data */
    int data[Maxsize];
    int front, rear; //对头指针和队尾指针
    int tag = 0;     //0：出队 1：入队
} SqQueue;

// 初始化队列
bool InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0;
    return true;
}
// 判断是否为空
bool QueueEmpty(SqQueue Q)
{

    if (Q.front == Q.rear && Q.tag == 0)
    {
        /* code */
        return true;
    }
    return false;
}
// 判断是否为满
bool QueueFull(SqQueue Q)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        /* code */
        return true;
    }
    return false;
}
// 入队操作
bool EnQueue(SqQueue &Q, int x)
{
    if (Q.front == Q.rear && Q.tag == 1)
    {
        /* code */
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % Maxsize;
    Q.tag = 1;
    return true;
}
bool EnElemsInQueue(SqQueue &Q)
{
    int x;
    if (QueueFull(Q))
    {
        /* code */
        return false;
    }
    printf("请输入入队元素:");
    scanf("%d", &x);
    printf("\n");
    while (x != 666)
    {
        /* code */
        EnQueue(Q, x);
        if (QueueFull(Q))
        {
            /* code */
            printf("队列已经满了\n");
            break;
        }
        printf("请输入入队元素:");
        scanf("%d", &x);
        printf("\n");
    }
    return true;
}
// 出队操作
bool DeQueue(SqQueue &Q, int &x)
{
    if (Q.rear == Q.front && Q.tag == 0)
    {
        /* code */
        return false;
    }
    x = Q.data[Q.front];
    Q.front--;
    Q.tag = 0;
    return true;
}
// 头元素取得
bool GetHeadQueue(SqQueue Q, int &x)
{
    if (Q.rear == Q.front && Q.tag == 0)
    {
        /* code */
        return false;
    }
    x = Q.data[Q.front];
    return true;
}
// 队列长度
void Length(SqQueue Q)
{
    printf("当前顺序队列长度%d", (Q.rear + Maxsize - Q.front) % Maxsize);
}
// 展示队列
void ShowQueue(SqQueue Q)
{
    int num = 0;
    while (Maxsize > num)
    {
        /* code */
        printf("%d\n", Q.data[num]);
        num++;
    }
}
int main()
{
    SqQueue Q;
    if (InitQueue(Q))
    {
        printf("初始化成功\n");
        /* code */
    }
    else
    {
        printf("初始化失败");
    }
    EnElemsInQueue(Q);
    ShowQueue(Q);
}