class Solution {
    using ll=long long;
    int n;
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        vector<vector<vector<ll>>>dp(n+1,
        vector<vector<ll>>(n+2,vector<ll>(2,-1)));
        return fun(0,1,1,piles,dp);
    }

    ll fun(int ind,int m,int turn,vector<int>&piles,
    vector<vector<vector<ll>>>&dp){
        if(ind==n)return 0;

        if(dp[ind][m][turn]!=-1)return dp[ind][m][turn];
        ll ans=turn==1?-1:INT_MAX;
        ll stone=0;
        for(int i=ind;i<min(n,ind+2*m);i++){
            stone+=piles[i];
            int len=i-ind+1;
            if(turn){
                
                ans=max(ans,stone+fun(i+1,max(m,len),0,piles,dp));
            }
            else{
                ans=min(ans,fun(i+1,max(m,len),1,piles,dp));
            }
        }
        return dp[ind][m][turn]= ans;
    }
};