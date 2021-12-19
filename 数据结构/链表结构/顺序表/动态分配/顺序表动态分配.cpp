#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#define InitSize 10
typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SeqList;

//初始化内存空间
void InitList(SeqList &L)
{
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

// 动态增加数组的长度

void IncreaseSzie(SeqList &L, int len)
{
    int *p = L.data;
    // 重新分配一组内存地址
    L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
    int *p_temp = L.data;
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}

// 主函数

int main()
{
    SeqList L;
    InitList(L);
    IncreaseSzie(L, 5);
    return 0;
}