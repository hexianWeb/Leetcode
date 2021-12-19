#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>
#include <string.h> //引入字符串数组

#define InitSize 10

typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SSTable;

// 初始化内存空间
void InitList(SSTable &L)
{
    L.MaxSize = InitSize;
    L.data = (int *)malloc(L.MaxSize * sizeof(int));
    L.length = 0;
}

// 普通
int Search_SSTable(SSTable T, int key)
{
    int i;
    for (i = 0; i < T.length && T.data[i] != key; ++i)
    {
        return i == T.length ? -1 : i;
    }
}

// 哨兵
// 优点 只需要判断元素是否匹配 不需要判断界限T.length是否被i越界 但是没有dio 用
int Sreach_Seq(SSTable T, int key)
{
    T.data[0] = key;
    int i;
    for (i = 0; T.data[i] != key; --i)
    {
        /* code */
        return i;
    }
}
// 查找效率分析
// 查找成功
// 数量级
// O(n)
// 时间复杂度(n+1)/2
// 查找失败
// n+1次

// 优化方案一 查找表中的元素有序存放（顺序表） 适用于失败多

// 查找失败
// ASL失败=（1+2+3+...+n+n）/n+1=n/2+n/n+1
// 一个成功节点的查找长度=自身所在的层数
// 一个失败节点的查找长度=父节点所在的层数
// 默认情况下 每个节点发生概率相同

// 优化方案二 被查概率不相等 查找概率大的放靠前的位置 适用于成功多
// 7：15%
// 13：5%
// 19：10%
// ...
// 43：2%
