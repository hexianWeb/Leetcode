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

// 核心代码实现

int merge(SSTABLE &L, int left, int mid, int right)
{
    // 辅助数组的建立
    // int help[right - left + 1];
    int n = right - left + 1;
    int *help;
    help = (int *)malloc(n * sizeof(int));
    // 辅助数组使用的变量
    int i = 0;
    // 分为左右部分
    int p1 = left;
    int p2 = mid + 1;
    // 求小和关键变量的存储
    int res = 0;

    while (p1 <= mid && p2 <= right)
    {
        res += L.data[p1] < L.data[p2] ? (right - p2 + 1) * L.data[p1] : 0;
        help[i++] = L.data[p1] <= L.data[p2] ? L.data[p1++] : L.data[p2++];
    }
    while (p1 <= mid)
    {
        /* code */
        help[i++] = L.data[p1++];
    }
    while (p2 <= right)
    {
        /* code */
        help[i++] = L.data[p2++];
    }
    for (i = 0; i < (right - left + 1); i++)
    {
        /* code */
        // printf("%d", help[i]);
        L.data[left + i] = help[i];
    }
    // 使用完数组自动释放
    free(help);
    // 返回结果
    return res;
}
// 合并排序
int process_smallNum(SSTABLE &L, int left, int right)
{
    if (left == right)
    {
        return 0;
    }
    int mid = left + ((right - left) >> 1);

    // 先求左半边的小和 再求右边的小和 最后求合并后的小和
    return process_smallNum(L, left, mid) +
           process_smallNum(L, mid + 1, right) +
           merge(L, left, mid, right);
}

int main()
{
    SSTABLE L;
    InitSSTABLE(L);
    InsertNum(L);
    int num = process_smallNum(L, 0, L.Length - 1);
    printf("小和值为:%d", num);
    for (int i = 0; i < L.Length; i++)
    {
        /* code */
        printf("合并排序后元素:%d\n", L.data[i]);
    }
}