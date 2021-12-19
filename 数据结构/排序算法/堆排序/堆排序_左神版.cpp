#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// 一个普通的交换函数
void swap(int &a, int &b)
{
    // 最后一步 自己和自己异或 结果为0
    // a ^= b;
    // b ^= a;
    // a ^= b;
    int temp;
    temp = a;
    a = b;
    b = temp;
}
// 堆化函数
void heapify(int A[], int index, int heapSize)
{
    int left = index * 2 + 1; // 左孩子的下标

    while (left < heapSize) //下方有孩子
    {
        // 两孩子中 谁的值大 谁的下标给largest
        int largest = left + 1 < heapSize && A[left + 1] > A[left] ? left + 1 : left;
        // 子元素跟父节点比较
        largest = A[largest] > A[index] ? largest : index;
        // 如果最大的仍然是父节点 则不操作
        if (largest == index)
        {
            break;
        }
        // 若最大节点是子节点 则交换子与父的位置
        // 交换当前节点和父亲节点的值  //
        swap(A[largest], A[index]);
        //重置要审计的节点
        index = largest;
        // 重置左孩子下标
        left = index * 2 + 1;
    }
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

// 构建大根堆
void BuildMaxHeap(int A[], int heapSize)
{
    for (int i = heapSize / 2; i >= 0; i--)
    {
        heapify(A, i, heapSize);
    }
}

// 版本一
void HeapSort_BIG(int A[], int heapSize)
{
    BuildMaxHeap(A, heapSize);
    swap(A[0], A[--heapSize]);
    while (heapSize > 0)
    {
        heapify(A, 0, heapSize);
        swap(A[0], A[--heapSize]);
    }
}
// 版本二 左神版
// void HeapSort_BIG(int *A, int heapSize)
// {
//     // 只有1各元素 或者数组为空 不需要排序
//     if (A == NULL || heapSize < 2)
//     {
//         return;
//     }
//     // 建立大根堆
//     for (int i = 0; i < heapSize; i++)
//     {
//         heapInsert(A, i);
//     }
//     swap(A[0], A[--heapSize]);
//     while (heapSize > 0)
//     {
//         heapify(A, 0, heapSize);
//         swap(A[0], A[--heapSize]);
//     }
// }
void PrintValue(int A[], int heapSize)
{
    for (int i = 0; i < heapSize; i++)
    {
        cout << "左神版heapify大根堆元素A[" << i << "]:" << A[i] << endl;
    }
}
int main()
{
    // int A[] = {}
    // int A[] = {53, 17, 78, 9, 45, 65, 87, 32};
    int A[] = {2, 0, 2, 1, 1, 0};
    int heapSize = sizeof(A) / sizeof(A[1]);
    HeapSort_BIG(A, heapSize);
    // PrintValue(A, heapSize);
}