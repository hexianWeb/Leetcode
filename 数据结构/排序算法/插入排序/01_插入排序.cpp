/*
算法思想：每次将一个待排序的记录按其
关键字大小插入到前面已经排序好的子序
列中，直到全部记录插入完成
*/

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

// 插入数据函数 顺序表 444终止
void InsertNum(SSTable &T)
{
    int x;
    scanf("%d\n", &x);
    while (x != 444)
    {
        if (T.length < T.MaxSize)
        {
            T.data[T.length] = x;
            T.length++;
            scanf("%d", &x);
        }
        else
        {
            printf("数据已满 元素%d不采纳,\n", x);
            break;
        }
    }
}

// 展示数据函数
void showData(SSTable T)
{
    for (int i = 0; i < T.length; i++)
    {
        printf("%d\n", T.data[i]);
    }
}

// 交换函数 位运算代替
void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
// 初始化数据函数
void InitList(SSTable &T)
{
    T.MaxSize = InitSize;
    T.data = (int *)malloc(T.MaxSize * sizeof(int));
    T.length = 0;
}

// 插入排序
// 最好时间复杂度O（n）
// 最坏时间复杂度O（n²） 程序一般只关注最坏时间复杂度

void InsertSort(SSTable &T)
{
    InitList(T);
    InsertNum(T);
    int i, j, temp;
    for (i = 0; i < T.length; i++)
    {
        // 这里交换可以用异或运算代替
        // 往前看 一直小就一直往前换 换到前面不必后面大 或者前面没数了
        for (j = i - 1; j >= 0 && T.data[j] > T.data[j + 1]; --j)
        {
            swap(T.data[j], T.data[j + 1]);
            // temp = T.data[j];
            // T.data[j] = T.data[j + 1];
            // T.data[j + 1] = temp;
        }
    }
}

// 带哨兵算法
void Insert_Sort(SSTable &T)
{
    int i, j;
    for (i = 2; i < T.length; i++)
    {
        /* code */
        if (T.data[i] < T.data[i - 1])
        {
            T.data[0] = T.data[i - 1];
            for (j = i - 1; T.data[0] < T.data[j]; --j)
            {
                /* code */
                T.data[j + 1] = T.data[j];
            }
            T.data[j + 1] = T.data[0];
        }
    }
}

// 带哨兵+ 折半查找
void Insert_Binary_Search(SSTable &T)
{
    int i, j, low, high, mid;
    for (i = 2; i < T.length; i++)
    {
        /* code */
        T.data[0] = T.data[i];
        low = 1;
        high = i - 1;
        while (low <= high)
        {
            /* code */
            mid = (low + high) / 2;
            if (T.data[mid] > T.data[0])
            {
                /* code */
                high = mid - 1;
            }
            if (T.data[mid] < T.data[0])
            {
                /* code */
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= low; --j)
        {
            /* code */
            T.data[j + 1] = T.data[j];
        }
        T.data[low] = T.data[0];
    }
}
int main()
{
    SSTable T;
    InsertSort(T);
    showData(T);
}