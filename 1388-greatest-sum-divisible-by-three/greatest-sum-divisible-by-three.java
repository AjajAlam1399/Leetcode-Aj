class Solution {
    int dp[][];
    public int maxSumDivThree(int[] nums) {
        dp=new int[40005][3];
        for(int [] d : dp){
            Arrays.fill(d,-1);
        }
        return fun(0,0,nums);
    }

    int fun(int ind,int mod,int[]nums){

        if(ind==nums.length){
            if(mod==0)return 0;
            return -1000000000;
        }
        if(dp[ind][mod]!=-1)return dp[ind][mod];
        int not_taken=fun(ind+1,mod,nums);
        int taken=nums[ind]+fun(ind+1,(mod+nums[ind])%3,nums);
        return dp[ind][mod]=Math.max(taken,not_taken);
    }
}