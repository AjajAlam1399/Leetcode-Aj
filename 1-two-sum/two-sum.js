/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
    let map={};
    for(let i=0;i<nums.length;i++){
        let b=target-nums[i];
        if(map.hasOwnProperty(b)){
            return [map[b],i];
        }
        map[nums[i]]=i;
    }
    return [];
};