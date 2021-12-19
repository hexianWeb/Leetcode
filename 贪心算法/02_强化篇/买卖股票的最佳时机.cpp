#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
        {
            return 0;
        }

        int money = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            money += max(0, prices[i + 1] - prices[i]);
        }
        return money;
    }
};
