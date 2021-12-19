#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
    {
        return {};
    }
    // 将获取的数组按头元素从小到大排序
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);
    // 将数组剩余元素从头到尾遍历
    for (int i = 1; i < intervals.size(); i++)
    {
        int L = intervals[i][0];
        int R = intervals[i][1];
        // 如果 merged数组集中的最右边界小于当前区间的左边界 则无法合并 加入merge队列 成为最右区间
        if (merged.back()[1] < L)
        {
            merged.push_back({L, R});
        }
        // 否则 合并当前区间与merged的最右区间 ，更新后新的最右区间为两者之间的较大值
        else
        {
            merged.back()[1] = max(merged.back()[1], R);
        }
    }
    return merged;
}
