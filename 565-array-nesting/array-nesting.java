class Solution {
    boolean visted[];
    int dp[];
    public int arrayNesting(int[] nums) {
        int n=nums.length;
        visted = new boolean[n];
        dp = new int [n];

        Arrays.fill(visted,false);
        Arrays.fill(dp,0);
        int ans=1;
        for(int i=0;i<n;i++){
            if(!visted[i]){
                int curr = dfs(i,1,nums);
                ans=Math.max(ans,curr);
            }
        }

        return ans;
    }

    int dfs(int node , int level , int nums[]){
        visted[node] = true;

        if(!visted[nums[node]]){
            return dp[node] = dfs(nums[node],level+1,nums);
        }
        else{
            if(dp[nums[node]]!=0){
                return dp[node] =  level+dp[nums[node]];
            }
            else{
                return dp[node] =  level;
            }
        }
    }
}