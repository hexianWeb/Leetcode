// 折半查找 仅适用于有序的顺序表
// 有序有序有序
#include <stdlib.h> //注意 malloc和free的函数都在stdlib里 注意引入
#include <stdio.h>

#define InitSize 10;

typedef struct
{
    int *data;
    int MaxSize;
    int length;
} SSTable;

// 初始化函数
void InitSSTable(SSTable &T)
{
    T.MaxSize = InitSize;
    T.data = (int *)malloc(T.MaxSize * sizeof(int));
    T.length = 0;
}
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
    printf("结束\n");
}

int Binary_Search(SSTable L, int key)
{
    // 定义 low high 指针
    int low = 0, high = L.length, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
        {
            /* code */
            return mid;
        }
        if (L.data[mid] > key)
        {
            high = mid - 1;
            /* code */
        }
        else if (L.data[mid] < key)
        {
            low = mid - 1;
        }
    }
    return -1;
}
int main()
{
    SSTable L;
    InitSSTable(L);
    InsertNum(L);
    int num = Binary_Search(L, 3);
    printf("折半查找次序为%d", num);
}
// 查找效率分析
/*
时间复杂度
    O(log2n)

*/
// PS： 失败节点=成功节点+1
// 折半查找的判定书是平衡二叉排序树qq
