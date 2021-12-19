// 输入: prices = [7, 1, 5, 3, 6, 4];
// 输出: 7
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。
// 示例 2:

// 输入: prices = [1,2,3,4,5]
// 输出: 4
// 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
//      注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 示例 3:

// 输入: prices = [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
//

/**·*·@param·{number[]}·prices·*·@return·{number}·*/
// 解法一----------------------------------------------------------------
var maxProfit = function (prices) {
  let flag_money = true;
  var sum = 0;
  for (let day = 0; day < prices.length; day++) {
    //   买股票
    console.log(flag_money);

    if (flag_money) {
      if (prices[day + 1] > prices[day]) {
        // console.log(prices[day]);
        sum = sum - prices[day];
        flag_money = false;
      }
    }
    // 卖股票
    else {
      if (prices[day + 1] < prices[day] || day == prices.length - 1) {
        sum = sum + prices[day];
        flag_money = true;
      }
    }
  }
  //   如果亏本就被长期持有
  if (sum < 0) {
    sum = 0;
  }
  return sum;
};
// 解法二-----------------------------------------------
var maxProfit = function (prices) {
  let ans = 0;
  for (let i = 1; i < prices.length; i++) {
    ans += Math.max(0, prices[i] - prices[i - 1]);
  }
  return ans;
};

prices = [6, 1, 3, 2, 4, 7];
let a = maxProfit(prices);
console.log(a);
// prices = [7, 1, 5, 3, 6, 4];
// prices = [1, 2, 3, 4, 5];
// prices = [7, 6, 4, 3, 1];
// [6,1,3,2,4,7]
