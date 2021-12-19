// 递归调用
#include <stdio.h>
#include <stdlib.h>

#define InitSize 10;
typedef struct
{
    int *data;
    int MaxSize;
    int Length;
} SSTABLE;

// 初始化函数
void InitSSTABLE(SSTABLE &L)
{
    L.MaxSize = InitSize;
    L.data = (int *)malloc(L.MaxSize * sizeof(int));
    L.Length = 0;
}

// 插入函数
void InsertNum(SSTABLE &L)
{
    int x;
    scanf("%d", &x);
    while (x != 444)
    {
        if (L.Length < L.MaxSize)
        {
            /* code */
            L.data[L.Length] = x;
            L.Length++;
            scanf("%d", &x);
        }
    }
}

int porcess_FindBigOne(SSTABLE &L, int left, int right)
{

    if (left == right)
    {
        return L.data[left];
    }
    // 最高效率位运算 向右移动一位等于/2
    int mid = left + ((right - left) >> 1);
    int leftMax = porcess_FindBigOne(L, left, mid);
    int rightMax = porcess_FindBigOne(L, mid + 1, right);

    //递归的核心步骤
    if (leftMax > rightMax)
    {
        /* code */
        return leftMax;
    }
    return rightMax;
}

int main()
{
    SSTABLE L;
    InitSSTABLE(L);
    InsertNum(L);
    int num = porcess_FindBigOne(L, 0, L.Length);
    printf("%d", num);
}
//类似于二叉树的后序遍历 ，只有叶子节点返回结果才能促使根节点开始运行
