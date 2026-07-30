class Solution {
    public int maxSubArray(int[] nums) {
        int currSum = 0;
        int ans = Integer.MIN_VALUE;

        for(int i=0;i<nums.length;i++){
            currSum += nums[i];
            ans = Math.max(ans,currSum);
            if(currSum<0)currSum = 0;
        }

        return ans;
    }
}