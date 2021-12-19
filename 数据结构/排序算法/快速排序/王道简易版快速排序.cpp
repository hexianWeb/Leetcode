// 快速排序简易
#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int low, int high)
{
    int pivot = A[low]; // 第一个元素作为基准元素
    while (low < high)  // 用low和high搜索并且确定最终位置
    {
        while (low < high && A[high] >= pivot)
        {
            --high;
        }
        A[low] = A[high]; //比基准元素小的元素移动到元素左端
        while (low < high && A[low] <= pivot)
        {
            ++low;
        }
        A[high] = A[low]; // 比基准打的元素移动到元素右端
    }
    A[low] = pivot;
    return low;
}
void QuickSort(int A[], int low, int high)
{
    if (low < high) //递归跳出条件
    {
        int pivotpos = Partition(A, low, high); //划分
        QuickSort(A, low, pivotpos - 1);        //左子表
        QuickSort(A, pivotpos + 1, high);       // 右字表
    }
}

int main()
{
    int A[] = {3, 1, 4, 2, 2};
    QuickSort(A, 0, 5);
    for (int i = 0; i < 5; i++)
    {
        /* code */
        printf("排序后的元素%d\n", A[i]);
    }
}