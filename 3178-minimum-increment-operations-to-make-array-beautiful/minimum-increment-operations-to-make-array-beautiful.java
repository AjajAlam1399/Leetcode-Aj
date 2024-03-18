class Solution {
    public long minIncrementOperations(int[] nums, int k) {
        int n=nums.length;
        long[][] dp=new long[n][4];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(0,3,nums,k,dp);
    }

    long fun(int ind,int skip,int[] nums,int k,long[][] dp){
        if(ind==nums.length){
            return 0;
        }
        if(dp[ind][skip]!=-1){
            return dp[ind][skip];
        }
        long no_change=Long.MAX_VALUE;
        if(skip>1){
            no_change=fun(ind+1,skip-1,nums,k,dp);
        }
        long change=Math.max((long)0,(long)(k-nums[ind]))+fun(ind+1,3,nums,k,dp);

        return dp[ind][skip]=Math.min(change,no_change);
    }
}