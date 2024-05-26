class Solution {
    int mod=1e9+7;
    using ll=long long;
public:
    int checkRecord(int n) {
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(3,vector<ll>(2,-1)));
        return fun(0,2,1,n,dp);
    }

    long long fun(int ind,int late,int absent,int n, vector<vector<vector<ll>>>&dp){

        if(ind==n)return 1;

        if(dp[ind][late][absent]!=-1)return dp[ind][late][absent];

        ll ab=0;
        ll pp=0;
        ll la=0;
        if(absent){
            ab=fun(ind+1,2,absent-1,n,dp);
        }
        if(late){
            la=fun(ind+1,late-1,absent,n,dp);
        }
        pp=fun(ind+1,2,absent,n,dp);
        
        return dp[ind][late][absent]=(ab%mod+pp%mod+la%mod)%mod;
    }
};