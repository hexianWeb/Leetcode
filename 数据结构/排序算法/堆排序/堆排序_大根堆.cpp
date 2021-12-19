#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
// len 改为heapsize***
void HeadAdjust(int A[], int k, int len)
{
    // A[0]暂存子树的根节点
    A[0] = A[k];
    // i 更改为left变量****
    for (int i = 2 * k; i <= len; i *= 2) //沿着k值对应的子树向下查找
    {
        if (i < len && A[i] < A[i + 1]) //选取子树中 值较大的当做比较对象
        {
            i++;
        }
        if (A[0] >= A[i]) // 满足根最大 大于左右子树条件
        {
            break;
        }
        else
        {
            A[k] = A[i]; // 根与较大子树的值相互调换
            k = i;       //检查 该子树是否满足当前堆的条件
        }
    }
    A[k] = A[0];
}

// 插入堆值(大根堆)
void heapInsert(int A[], int index)
{
    while (A[index] > A[(index - 1) / 2])
    {
        swap(A[index], A[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// 构建大堆
void BuildMaxHeap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len);
    }
}

void PrintValues(int *a, int len)
{
    for (int i = 1; i <= len; i++)
    {
        /* code */
        cout << "遍历数组元素:" << a[i] << endl;
    }
}
void HeapSort_BIG(int A[], int len)
{
    BuildMaxHeap(A, len);         // 建立一个初始的堆
    for (int i = len; i > 1; i--) //n-1趟的交换和建立堆的过程
    {
        swap(A[i], A[1]);        //栈顶和栈底元素交换
        HeadAdjust(A, 1, i - 1); //把剩余的待排序元素重新整理成堆
    }
}
int main()
{
    // int A[] = {0, 1, 4, 2, 5, 6};
    int A[] = {0, 86, 74, 53, 65, 34, 38, 46, 14, 27, 26};
    int len = sizeof(A) / sizeof(A[1]) - 1;
    // cout << "数组长度" << len << endl;
    BuildMaxHeap(A, len);
    // HeapSort_BIG(A, len);
    PrintValues(A, len);
}
