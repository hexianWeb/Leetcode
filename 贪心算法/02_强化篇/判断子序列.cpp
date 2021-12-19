#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string t, string s)
    {
        if (s.size() == 0)
        {
            return true;
        }
        int Length_S = s.size();
        int Length_T = t.size();
        if (Length_S != 0 && Length_T == 0)
        {
            return false;
        }

        // S字符串的指针
        int i = 0;
        // T字符串的指针
        int j = 0;
        while (i < Length_S && j < Length_T)
        {
            if (s.at(i) == t.at(j))
            {
                j++;
                i++;
            }
            else
            {
                j++;
            }
        }
        return i >= Length_S;
    }
};
// 双指针匹配算法

int main()
{
    Solution sol;
    string s = "hello";
    string c = "hel";
    if (sol.isSubsequence(c, s))
    {
        cout << "匹配成功";
    }
    else
    {
        cout << "失败";
    }
}