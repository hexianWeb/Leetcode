#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>        //max 函数
#include <unordered_set> //哈希表头文件
using namespace std;

// 利用迭代器将容器中的数据输出
void Print_VALUE(vector<int> obj)
{
    vector<int>::iterator it; //声明一个迭代器 来访问vector容器的元素
    for (it = obj.begin(); it != obj.end(); it++)
    {
        cout << *it << " ";
    }
}

//方案一 动态规划
int maxSubArray(vector<int> &nums)
{
    int pre = 0;
    int maxAns = nums[0];
    for (const auto &x : nums)
    {
        pre = max(pre + x, x);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

int main()
{
    vector<int> obj;
    for (int i = 0; i < 10; i++)
    {
        obj.push_back(i * 1);
    }
    cout << "得出的结果为：" << maxSubArray(obj) << endl;
}