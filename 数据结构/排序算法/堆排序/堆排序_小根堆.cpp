#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 一个普通的交换函数
void swap(int &a, int &b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}
// 一个普通的数组输出函数
void PrintValues(int *a, int len)
{

    for (int i = 1; i <= len; i++)
    {
        cout << "遍历的元素为" << a[i] << endl;
    }
}

// 插入堆值(小根堆)
void heapInsert(int A[], int index)
{
    while (A[index] < A[(index - 1) / 2])
    {
        swap(A[index], A[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void HeadAdjust(int A[], int k, int len)
{
    // 0位置存储调整对象
    A[0] = A[k];
    // 沿着K节点向下寻找子树中的值
    for (int i = 2 * k; i <= len; i *= 2)
    {
        // 选取子树中元素更小的元素
        if (i < len && A[i] > A[i + 1])
        {
            i++;
        }
        // 如果当前比对的值小于根节点
        if (A[0] <= A[i])
        {
            /* code */
            break;
        }
        else
        {
            // 根与较小的子树的值相互调换
            A[k] = A[i];
            // 检查后续子树是否满足堆条件
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMinHeap(int A[], int len)
{
    // 整理堆
    for (int i = len / 2; i > 0; i--)
    {
        HeadAdjust(A, i, len);
    }
}

void HeapSort_SMALL(int A[], int len)
{
    BuildMinHeap(A, len);
    for (int i = len; i > 1; i--)
    {
        swap(A[i], A[1]);
        HeadAdjust(A, 1, i - 1);
    }
}
int main()
{
    // int test[] = {0, 3, 2, 1};
    int A[] = {0, 53, 17, 78, 9, 45, 65, 87, 32};
    int len = sizeof(A) / sizeof(A[1]) - 1;
    HeapSort_SMALL(A, len);
    PrintValues(A, len);
}