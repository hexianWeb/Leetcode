#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define MaxSize 10

typedef struct
{
    /* data */
    int data[MaxSize];
    int top; //栈顶指针
} SeqStack;
// 初始化
void InitStack(SeqStack &S)
{
    S.top = -1; //初始指针位置指向-1
}
// 判断栈空
bool StackEmpty(SeqStack S)
{
    if (S.top == -1)
    {
        /* code */
        return true;
    }
    return false;
}
// 新元素入栈
bool Push(SeqStack &S, int x)
{
    if (S.top == MaxSize - 1)
    {
        /* code */
        return false;
    }
    S.top = S.top + 1;
    S.data[S.top] = x;
    return true;
}
void PushElem(SeqStack &S)
{
    int x;
    while (S.top < 9)
    {
        /* code */
        printf("%d", S.top);
        scanf("%d", &x);
        Push(S, x);
    }
}
// 出栈操作
bool Pop(SeqStack &S, int &x)
{
    if (S.top == -1)
    {
        /* code */
        return false;
    }
    x = S.data[S.top];
    S.top = S.top - 1;
    return true;
}
bool getTop(SeqStack S, int &top_value)
{
    if (S.top == -1)
    {
        /* code */
        return false;
    }
    top_value = S.data[S.top];
    return true;
}
//  显示数据
void ShowStack(SeqStack &S)
{
    while (S.top != -1)
    {
        /* code */

        printf("栈内元素：%d\n", S.data[S.top]);
        S.top--;
    }
}
int main()
{
    SeqStack S;
    InitStack(S);
    int x;
    int topValue;
    if (StackEmpty(S))
    {
        /* code */
        printf("栈初始化成功\n");
    }
    else
    {
        printf("栈 初始化失败\n");
    }
    if (Push(S, 1))
    {
        /* code */
        printf("元素入栈成功\n");
    }
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    // PushElem(S);
    getTop(S, topValue);
    printf("查找元素为:%d", topValue);
    // Pop(S, x);
    printf("栈顶元素%d\n", x);
    printf("-----栈-------\n");
    ShowStack(S);
    printf("-----栈-------\n");
}