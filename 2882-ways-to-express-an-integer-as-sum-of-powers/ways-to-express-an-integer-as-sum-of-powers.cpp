class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int numberOfWays(int n, int x) {
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        return fun(1,n,n,x,dp);
    }

    ll fun(ll i,ll target,int &n,int &x,vector<vector<ll>>&dp){

        if(i>n){
            return target==0;
        }

        if(dp[i][target]!=-1)return dp[i][target];

        ll not_taken=fun(i+1,target,n,x,dp);
        ll taken=0;
        ll powValue=(ll)pow(i,x);
        if(target>=powValue){
            taken=fun(i+1,target-powValue,n,x,dp);
        }

        return dp[i][target]=(taken%mod+not_taken%mod)%mod;
    }
};