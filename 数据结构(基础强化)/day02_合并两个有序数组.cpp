#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>        //max 函数
#include <unordered_map> //哈希表头文件
#include <unordered_set>
using namespace std;
// 方法二：双指针
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)

{
    int p1 = 0, p2 = 0;
    int sorted[m + n];
    int cur;
    while (p1 < m || p2 < n)
    {
        if (p1 == m)
        {
            cur = nums2[p2++];
        }
        else if (p2 == n)
        {
            cur = nums1[p1++];
        }
        else if (nums1[p1] <= nums2[p2])
        {
            cur = nums1[p1++];
        }
        else
        {
            cur = nums2[p2++];
        }
        sorted[p1 + p2 - 1] = cur;
    }
    for (int i = 0; i != m + n; i++)
    {
        nums1[i] = sorted[i];
    }
}