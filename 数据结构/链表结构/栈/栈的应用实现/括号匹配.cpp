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
// 多个元素入栈
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
// 核心算法实现
// 双引号中间的数据视作字符串，单引号中间的数据视作字符。
bool braketCheck(char str[], int length)
{
    SeqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        /* code */
        if (str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            /* code */
            Push(S, str[i]);
        }
        else
        {
            if (StackEmpty(S))
            {
                /* code */
                printf("匹配失败");
                return false;
            }

            int x;
            Pop(S, x);
            if (str[i] == ')' && x != '(')
            {
                /* code */
                return false;
            }
            if (str[i] == ']' && x != '[')
            {
                /* code */
                return false;
            }
            if (str[i] == '}' && x != '{')
            {
                /* code */
                return false;
            }
        }
    }
    return StackEmpty(S);
}
int main()
{
    char str[] = {'{', '{', '(', ')', '}', '}', ']'};
    int length = 7;
    if (braketCheck(str, length))
    {
        /* code */
        printf("匹配成功\n");
    }
    else
    {
        printf("匹配失败\n");
    }
}