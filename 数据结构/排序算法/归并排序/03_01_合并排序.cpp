// 递归调用
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define InitSize 10;
using namespace std;
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

void merge(SSTABLE &L, int left, int mid, int right)
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

    while (p1 <= mid && p2 <= right)
    {
        /* code */
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
    cout << "归并排序" << endl;
    for (i = 0; i < (right - left + 1); i++)
    {
        /* code */
        cout << " " << help[i];
        L.data[left + i] = help[i];
    }
    cout << "-----------" << endl;

    // 使用完数组自动释放
    free(help);
}
// 合并排序
void process_MergeSort(SSTABLE &L, int left, int right)
{
    if (left == right)
    {
        return;
    }
    int mid = left + ((right - left) >> 1);

    process_MergeSort(L, left, mid);
    process_MergeSort(L, mid + 1, right);
    merge(L, left, mid, right);
}

int main()
{
    SSTABLE L;
    InitSSTABLE(L);
    InsertNum(L);
    process_MergeSort(L, 0, L.Length - 1);
    for (int i = 0; i < L.Length; i++)
    {
        /* code */
        printf("合并排序后元素:%d\n", L.data[i]);
    }
}