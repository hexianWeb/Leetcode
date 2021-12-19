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
    // printf("原地址位置位于 %p\n", p);
    L.data = (int *)malloc((InitSize + len) * sizeof(int));
    int *p_temp = L.data;
    // printf("现地址位于 %p\n", p_temp);d
    for (int i = 0; i < L.length; i++)
    {
        /* code */
        L.data[i] = p[i];
    }
    L.MaxSize = L.MaxSize + len;
    free(p);
}
//  插入操作 参数为 被操作对象顺序表  插入位序 插入的元素值
void ListInsert(SeqList &L, int i, int e)
{
    printf("插入开始");
    for (int j = L.MaxSize; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}
// 主函数

int main()
{
    SeqList L;
    InitList(L);
    ListInsert(L, 1, 10);
    for (int i = 0; i < L.MaxSize; i++)
    {
        printf("value: %d\n ", L.data[i]);
    }
    return 0;
}