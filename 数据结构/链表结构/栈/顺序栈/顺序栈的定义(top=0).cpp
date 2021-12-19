#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define MaxSize 10

typedef struct
{
    int data[MaxSize];
    int top;
} SeqStack;
// 初始化
void InitStack(SeqStack &S)
{
    S.top = 0; //这里指向的是下一个操作对象
}
// 判断栈空
bool StackEmpty(SeqStack S)
{
    if (S.top == 0)
    {
        /* code */
        return true;
    }
    return false;
}
// 入栈操作
bool Push(SeqStack &S, int x)
{
    if (S.top == MaxSize)
    {
        /* code */
        return false;
    }
    S.data[S.top] = x;
    S.top++;
}
// 出栈操作
bool Pop(SeqStack &S, int &x)
{
    if (S.top == 0)
    {
        return false;
        /* code */
    }
    S.top = S.top - 1;
    x = S.data[S.top];
    return true;
}
int main()
{
}