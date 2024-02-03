class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
         vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int maxele=-1;
            int cnt=0;
            int maxval=-1;
            for(int j=i;j<min(i+k,n);j++){
                cnt++;
                maxele=max(maxele,arr[j]);
                int sum=cnt*maxele+dp[j+1];
                maxval=max(maxval,sum);
            }
             dp[i]= maxval;
        }
        return dp[0];
    }
};