/**
 * @param {number[]} nums
 * @return {number}
 */
// 解法一--------------------------------------
// var removeDuplicates = function (nums) {
//   // 支线 数组为空
//   if (nums.length == 0) {
//     return 0;
//   }
//   var count = 1;
//   for (let i = 0; i < nums.length - 1; i++) {
//     if (nums[i] == nums[i + 1]) {
//       nums.splice(i, 1);
//       i--;
//       continue;
//     } else {
//       count++;
//     }
//   }
//   return count;
// };
// nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
// let anwer = removeDuplicates(nums);
// console.log(anwer);
// 解法二
var removeDuplicates = function (nums) {
  const n = nums.length;
  if (n === 0) {
    return 0;
  }
  let fast = 1,
    slow = 1;
  while (fast < n) {
    if (nums[fast] !== nums[fast - 1]) {
      nums[slow] = nums[fast];
      ++slow;
    }
    ++fast;
  }
  return slow;
};
nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
let anwer = removeDuplicates(nums);
console.log(nums);

// 示例 1：

// 输入：nums = [1,1,2]
// 输出：2, nums = [1,2]
// 解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
// 示例 2：

// 输入：nums = [0,0,1,1,1,2,2,3,3,4]
// 输出：5, nums = [0,1,2,3,4]
// 解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
