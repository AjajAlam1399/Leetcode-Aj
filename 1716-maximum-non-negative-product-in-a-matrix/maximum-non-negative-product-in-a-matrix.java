class Solution {
    int mod=1000000000+7;
    public int maxProductPath(int[][] grid) {
        
        int n=grid.length;
        int m=grid[0].length;
        long [][][]dp= new long[n][m][2];
        dp[0][0][0]=(long)grid[0][0];
        dp[0][0][1]=(long)grid[0][0];
        for(int i=1;i<m;i++){
            dp[0][i][0]=(long)grid[0][i]*dp[0][i-1][0];
            dp[0][i][1]=(long)grid[0][i]*dp[0][i-1][1];
        }
        for(int i=1;i<n;i++){
            dp[i][0][0]=(long)grid[i][0]*dp[i-1][0][0];
            dp[i][0][1]=(long)grid[i][0]*dp[i-1][0][1];
        }
        long ans=-1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                long min=(long)grid[i][j]*Math.min(dp[i-1][j][0],dp[i][j-1][0]);
                long max=(long)grid[i][j]*Math.max(dp[i-1][j][1],dp[i][j-1][1]);
                dp[i][j][0]=Math.min(min,max);
                dp[i][j][1]=Math.max(min,max);
            }
        }

        ans=dp[n-1][m-1][1];
        return ans<0?-1:(int)(ans%mod);

    }
}