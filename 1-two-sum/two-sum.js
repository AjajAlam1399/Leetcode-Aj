/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let arr = nums.map((val, ind) => {
        return { val, ind };
    });
    arr.sort((a, b) =>a.val - b.val);
    let n = nums.length;
    let i = 0;
    let j = n - 1;
    let ans = [];
    while (i < j) {
        let sum = arr[i].val + arr[j].val;
        if (sum == target) {
            return [arr[i].ind, arr[j].ind];
        }
        else if (sum < target) {
            i++;
        }
        else {
            j--;
        }
    }
    return ans;
};