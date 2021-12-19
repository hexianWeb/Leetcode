#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <string.h> //引入字符串数组

#define MAXLEN 255
// 定义结构体 静态数组实现 随机存储 但一旦存入 难以更改
typedef struct
{
    /* data */
    char ch[MAXLEN];
    int length;
} SString;
// 动态数组实现 用完需要手动free 而静态可以系统自动回收 但一次性需要分配更多的空间
typedef struct
{
    /* data */
    char *ch;
    int length;
} HString;

// 求串长操作
int StrLength(SString S)
{
    int i = 0;
    while (S.ch[i] != '\0')
    {
        /* code */
        i++;
    }
    return i;
}
// 清空操作
bool ClearString(SString &S)
{
    if (S.length == 0)
    {
        /* code */
        return false;
    }
    S.length = 0;
    return true;
}
// 求子串操作
bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.length || pos < 1 || len > 0)
    {
        /* code */
        return false;
    }
    for (int i = pos; i < pos + len; i++)
    {
        /* code */
        Sub.ch[i - pos + 1] = S.ch[i];
        Sub.length = len;
    }
    return true;
}
// // 比较一样操作
// bool StrSample(SString S, SString T)
// {
//     if (S.length == T.length)
//     {
//         /* code */
//         return true;
//     }
//     return false;
// }
// 比较大小操作
bool StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        /* code */
        if (S.ch[i] != T.ch[i])
        {
            /* code */
            if (S.ch[i] - T.ch[i] > 0)
            {
                /* code */
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    if (S.length - T.length > 0)
    { /* code */
        /* code */
        return true;
    }
    else
    {
        return false;
    }
}
// 求子串定位操作
int Index(SString S, SString T)
{
    int i = 1, n = StrLength(S), m = StrLength(T);
    SString sub;
    while (i < n - m + 1)
    {
        /* code */
        SubString(sub, S, i, m);
        if (!StrCompare(S, T))
        {
            /* code */
            i++;
        }
        else
        {
            return i;
        }
    }
    return -1;
}
// 赋值操作
bool StrAssign(SString &S, char *a1)
{
    int i = 0;
    strcpy(S.ch, a1);
    S.length = StrLength(S);
    return true;
}
void ShowStr(SString S)
{
    /* code */
    printf("%s\n", S.ch);
}
int main()
{
    SString S;
    SString T;
    char a1[] = "HELLO WORLD";

    char a2[] = "HELLO C++";

    if (StrAssign(S, a1))
    {
        /* code */
        printf("S1赋值操作成功\n");
    }
    if (StrAssign(T, a2))
    {
        /* code */
        printf("T1赋值操作成功\n");
    }
    if (StrCompare(S, T))
    {
        /* code */
        printf("S比T大\n");
    }
    else
    {
        printf("T比S大\n");
    }

    int length = StrLength(S);
    printf("长度为%d\n", length);
    ShowStr(S);
    ShowStr(T);
}