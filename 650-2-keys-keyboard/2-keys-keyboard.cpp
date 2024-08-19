class Solution {
    using ll=long long;
public:
    int minSteps(int n) {
        if(n==1)return 0;
        vector<vector<ll>>dp(n+1,vector<ll>(n+1,-1));
        return fun(1,1,n,dp)+1;
    }

    ll fun(int c,int p,int &n,vector<vector<ll>>&dp){
        if(c>n)return 1e3;
        if(c==n)return 0;
        if(dp[c][p]!=-1)return dp[c][p];
        ll copy=n;
        ll paste=n;
        if(c==p){
            paste=1+fun(c+p,p,n,dp);
        }
        else{
            paste=1+fun(c+p,p,n,dp);
            copy=1+fun(c,c,n,dp);
        }
        return dp[c][p]=min(copy,paste);
    }
};