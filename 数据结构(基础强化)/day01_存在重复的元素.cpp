#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set> //哈希表头文件
using namespace std;
// 方法一 数字从小到大排序 然后对比相邻两个元素是否相等

bool containDuplocate_01(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            return true;
        }
    }
    return false;
}

// 方法二 哈希表
// 将每一个第一次监测到的元素插入哈希表中
// 如果表中已经存在该元素 说明重复
bool containDuplocate_02(vector<int> &nums)
{
    unordered_set<int> s;
    for (int x : nums)
    {
        // cout << x;
        if (s.find(x) != s.end())
        {
            return true;
        }
        s.insert(x);
    }
    return false;
}

int main()
{
    vector<int> obj;
    for (int i = 0; i < 5; i++)
    {
        obj.push_back(i);
    }
    // obj.push_back(0);
    if (!containDuplocate_02(obj))
    {
        cout << "数组没有重复元素" << endl;
    }
    else
    {
        cout << "数组中有重复元素" << endl;
    }
}