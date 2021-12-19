// 存在重复元素
// 给定一个整数数组，判断是否存在重复元素。

// 如果存在一值在数组中出现至少两次，函数返回 true 。如果数组中每个元素都不相同，则返回 false 。

//

// 示例 1:

// 输入: [1,2,3,1]
// 输出: true
// 示例 2:

// 输入: [1,2,3,4]
// 输出: false
// 示例 3:

// 输入: [1,1,1,3,3,4,3,2,4,2]
// 输出: true
/**
 * @param {number[]} nums
 * @return {boolean}
 */
// let nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2];
let nums = [1, 2, 3, 4];
// 解法一 先排序 后破解 单指针

var containsDuplicate = function (nums) {
  nums.sort();
  if (nums.length == 0) {
    return false;
  }
  let fast = 1;
  while (nums.length > fast) {
    if (nums[fast] == nums[fast - 1]) {
      return true;
    }
    fast++;
  }
  return false;
};

//  解法二 哈希表
// 设置set合集 forof遍历 判断如果has元素 则返回true
var containsDuplicate = function (nums) {
  const set = new Set();
  for (const x of nums) {
    if (set.has(x)) {
      return true;
    }
    set.add(x);
  }
  return false;
};

console.log(containsDuplicate(nums));
