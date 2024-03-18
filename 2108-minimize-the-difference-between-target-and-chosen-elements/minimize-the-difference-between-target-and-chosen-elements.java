class Solution {
    public int minimizeTheDifference(int[][] mat, int target) {
        int n=mat.length;
        int[][] dp=new int[n][n*70+1];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(0,0,mat,target,dp);
    }

    int fun(int i,int sum,int[][]mat,int target,int[][] dp){

        if(i==mat.length){
            return Math.abs(sum-target);
        }

        if(dp[i][sum]!=-1){
            return  dp[i][sum];
        }

        int ans=Integer.MAX_VALUE;
        for(int j=0;j<mat[0].length;j++){
            ans=Math.min(ans,fun(i+1,sum+mat[i][j],mat,target,dp));
        }

        return dp[i][sum]=ans;
    }
}