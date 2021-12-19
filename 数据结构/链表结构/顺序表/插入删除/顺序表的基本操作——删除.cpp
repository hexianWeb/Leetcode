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
    printf("插入开始%d", e);
    for (int j = L.MaxSize; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
}
// 删除操作 并将删除元素返回
// 注意 &符号的作用
// 实参通常是通过值传递给函数的，这意味着形参接收的只是发送给它们的值的副本，它们存储在函数的本地内存中。对形参值进行的任何更改都不会影响原始实参的值。
// 但是使用引用变量作为形参时，它将变为实参列表中相应变量的别名，对形参进行的任何更改都将真正更改正在调用它的函数中的变量。当以这种方式将数据传递给形参时，该实参被称为按引用传递。
void ListDelete(SeqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        printf("删除失败");
        return;
    }
    e = L.data[i - 1];
    for (int j = i; i < L.MaxSize; i++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    printf("删除操作已经完成/n");
}
// 主函数

int main()
{
    SeqList L;
    InitList(L);
    ListInsert(L, 1, 10);
    ListInsert(L, 2, 10);
    int e = -1;
    ListDelete(L, 2, e);
    printf("%d", e);
    for (int i = 0; i < L.MaxSize; i++)
    {
        printf("value: %d\n ", L.data[i]);
    }
    return 0;
}