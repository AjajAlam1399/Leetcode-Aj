class Solution {
    int mod=1e9+7;
    using ll=long long;

public:
    int numTrees(int n) {
        
        //code here
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,0));
        for(int s=n;s>=0;s--){
            for(int e=n;e>=0;e--){
                if(s+e==2*n){
                    dp[s][e]=1;
                }
                else{
                    long long cnt=0;
                    if(s<n){
                        cnt+=dp[s+1][e];
                    }
                    if(e<s){
                        cnt+=dp[s][e+1];
                    }
                    dp[s][e]=cnt;
                }
            }
        }
        return (int)dp[0][0];

    }
};