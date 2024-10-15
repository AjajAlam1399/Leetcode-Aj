class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=1;j<=i;j++){
                int left=i-j;
                int right=i-left-1;
                sum+=dp[left]*dp[right];
            }
            dp[i]=sum;
        }
        return dp[n];
    }
};