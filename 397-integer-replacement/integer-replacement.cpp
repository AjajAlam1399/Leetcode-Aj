class Solution {
    using ll=long long;
public:
    int integerReplacement(int n) {
        
        unordered_map<ll,ll>dp;
        return fun(n,dp);
    }

    int fun(ll n,unordered_map<ll,ll>&dp){
        if(n==1){
            return 0;
        }

        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        ll even=0;
        ll odd=0;

        if(n%2==0){
            even=1+fun(n/2,dp);
        }
        else{
            odd=min(1+fun(n+1,dp),1+fun(n-1,dp));
        }
         dp[n]=even+odd;
         return dp[n];
    }
};