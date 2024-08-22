class Solution {
    using ll=long long ;
    int n;
public:
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();

        vector<ll>dp(n+1,-1e9);
        ll sum=0;

        ll val=fun(0,stoneValue,dp);
        if(val==0)return "Tie";
        return val>0?"Alice":"Bob";
    }

    ll fun(int ind,vector<int>& stoneValue,vector<ll>&dp){

        if(ind==n){
            return 0;
        }

        if(dp[ind]!=-1e9)return dp[ind];

        ll ans=-1e9;

        ll stone=0;
        for(int i=ind;i<min(ind+3,n);i++){
            stone+=stoneValue[i];
            ans=max(ans,stone-fun(i+1,stoneValue,dp));
        }

        return dp[ind]=ans;
    }
};