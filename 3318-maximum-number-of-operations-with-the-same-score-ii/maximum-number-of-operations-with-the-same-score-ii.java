class Solution {
    public int maxOperations(int[] nums) {
        int n=nums.length;
        int maxele=0;
        int [][]dp=new int[n][n];
            for(int j=0;j<n;j++){
                Arrays.fill(dp[j],-1);
            }
            int prev1=nums[0]+nums[1];
            int prev2=nums[n-1]+nums[n-2];
            int prev3=nums[0]+nums[n-1];
            return 1+Math.max(fun(prev1,2,n-1,nums,dp),Math.max(fun(prev2,0,n-3,nums,dp),fun(prev3,1,n-2,nums,dp)));
        
    }

    int fun(int prev,int i,int j,int []nums,int [][]dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        if(prev==nums[i]+nums[i+1]){
            ans=Math.max(ans,1+fun(nums[i]+nums[i+1],i+2,j,nums,dp));
        }
        if(prev==nums[j]+nums[j-1]){
            ans=Math.max(ans,1+fun(nums[j]+nums[j-1],i,j-2,nums,dp));
        }
        if(prev==nums[i]+nums[j]){
            ans=Math.max(ans,1+fun(nums[i]+nums[j],i+1,j-1,nums,dp));
        }
        return dp[i][j]=ans;
    }
}