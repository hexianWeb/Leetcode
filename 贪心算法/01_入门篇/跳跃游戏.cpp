#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        // 你可用的步数
        int reach = 0;
        for (int i = 0; i < n; i++)
        {
            // 当前的位置你可用的步数到达不了
            if (i > reach)
            {
                return false;
            }
            // 当前位置 +当前获取的点数 与你原本可用的步数作比较 取最大值
            reach = max(i + nums[i], reach);
        }
        return true;
    }
};