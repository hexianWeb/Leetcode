#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>        //max 函数
#include <unordered_map> //哈希表头文件
#include <unordered_set>
using namespace std;

// 方法一 暴力枚举

vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}

// 方法二 哈希表
vector<int> twoSum_02(vector<int> &nums, int target)
{
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++)
    {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end())
        {
            return {it->second, i};
        }
        else
        {
            hashtable[nums[i]] = i;
        }
    }
    return {};
}