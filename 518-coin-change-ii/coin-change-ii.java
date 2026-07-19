class Solution {
    int[][] dp;
    public int change(int amount, int[] coins) {
        int n = coins.length;
        dp = new int [n][amount+2];
        for(int i = 0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(n-1 , amount , coins);
    }

    int fun(int ind , int target , int [] coins){

        if(ind < 0 ){
            return target==0 ? 1 : 0;
        }

        if(dp[ind][target]!=-1)return dp[ind][target];

        int not_taken = fun(ind-1, target, coins);
        int taken = 0;

        if(target>=coins[ind]){
            taken = fun(ind , target - coins[ind],coins);
        }

        return dp[ind][target] =  taken+not_taken;
    }
}