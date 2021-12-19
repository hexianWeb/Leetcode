// 递归调用
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

void swap(int arr[], int a, int b)
{
    arr[a] ^= arr[b];
    arr[b] ^= arr[a];
    arr[a] ^= arr[b];
}
// 处理数组arr 从L到R的函数
// 默认以arr的R作为基准数 对arr进行快速排序
// 类似与 <p ==P=== p>
// 返回结果给予快速排序左右边界 故为长度为2的数组 res[0] 左 res[1] 右
// 这也是解决荷兰国旗问题的核心代码
int *partition(int arr[], int L, int R)
{
    int less = L - 1; //<右边界
    int more = R;     // >左边界 为什么不是 R+1
    while (L < more)
    {
        // 当前值小于基准值
        if (arr[L] < arr[R])
        {
            printf("左基准交换一次");
            swap(arr, ++less, L++); //当arr[L]对应的数小于基准值时 L处与 <区右边界的**下一个数**作交换 ++less不仅起到了扩充边界的作用
        }
        // 当前值大于基准值
        else if (arr[L] > arr[R])
        {
            swap(arr, --more, L); //此时 L所在下标原地不动
        }
        else
        {
            L++;
        }
    }
    swap(arr, more, R); //将基准值换回中心
    int *res = new int[2];
    res[0] = less + 1;
    res[1] = more;
    printf("%d", res[0]);
    return res;
}

// 快速排序流程代码
void quickSort(int arr[], int L, int R)
{
    if (L < R)
    {
        // swap(arr, L + (int)(rand() % 11 / 10 * (R - L + 1)), R);
        int *res = partition(arr, L, R);
        quickSort(arr, L, res[0] - 1);
        quickSort(arr, res[1] + 1, R);
    }
}
int main()
{
    int arr[] = {3, 1, 2, 4};
    quickSort(arr, 0, 4);
    for (int i = 0; i < 4; i++)
    {
        printf("排序后的元素%d\n", arr[i]);
    }
}