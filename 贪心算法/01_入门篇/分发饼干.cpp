#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int findGreedyWay(vector<int> &g, vector<int> &s)
    {
        // 贪心算法 万事先排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int numOfChild = g.size();
        int numOfCookies = s.size();
        // 计数器 记录当前孩子已经满足的数量
        int count = 0;
        for (int i = 0, j = 0; i < numOfChild && j < numOfCookies; i++)
        {
            //当饼干还有更大的 并且当前饼干满足不了孩子时候
            while (j < numOfCookies && g[i] > s[j])
            {
                j++;
            }
            if (j < numOfCookies)
            {
                count++;
                j++;
            }
        }
        return count;
    }
};

int main()
{
    vector<int> g;
    // g = {1, 2, 3, 4};
    g = {1, 1, 1, 1};
    vector<int> s;
    s = {1, 2, 3};
    Solution solution;
    cout << solution.findGreedyWay(g, s);
}
// 例：「力扣」第 455 题：分发饼干（简单）
// 假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

// 对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

// 示例 1:

// 输入: g = [1,2,3], s = [1,1]
// 输出: 1
// 解释:
// 你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
// 虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
// 所以你应该输出1。
// 示例 2:

// 输入: g = [1,2], s = [1,2,3]
// 输出: 2
// 解释:
// 你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
// 你拥有的饼干数量和尺寸都足以让所有孩子满足。
// 所以你应该输出2.

// 作者：力扣 (LeetCode)
// 链接：https://leetcode-cn.com/leetbook/read/greedy/rveyb6/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。