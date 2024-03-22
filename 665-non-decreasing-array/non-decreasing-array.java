class Solution {
    public boolean checkPossibility(int[] nums) {
        int n=nums.length;
       int dp[]=new int[n];
       Arrays.fill(dp,1);
        int ans=1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>=nums[j] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            ans=Math.max(ans,dp[i]);
        }

        return ans>=n-1?true:false;
    }
}