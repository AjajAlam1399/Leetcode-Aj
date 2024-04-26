class Solution {
    using ll=long long ;
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<ll>>dp(n+1,vector<ll>(n+2,-1));
        return fun(0,-1,grid,dp);
    }

    ll fun(int ind,int prev,vector<vector<int>>& grid,vector<vector<ll>>&dp){
        if(ind==grid.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        ll ans=INT_MAX;
        for(int j=0;j<grid[0].size();j++){
            ll sum=INT_MAX;
            if(j!=prev){
                sum=grid[ind][j]+fun(ind+1,j,grid,dp);
            }
            ans=min(ans,sum);
        }
        return dp[ind][prev+1]= ans;
    }
};