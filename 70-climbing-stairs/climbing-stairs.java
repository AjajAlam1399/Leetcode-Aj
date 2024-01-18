class Solution {
    public int climbStairs(int n) {
        int arr[]=new int[n+1];
        Arrays.fill(arr,-1);
        return fun(n,arr);
    }

    int fun(int n,int dp[]){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=fun(n-1,dp)+fun(n-2,dp);
    }
}