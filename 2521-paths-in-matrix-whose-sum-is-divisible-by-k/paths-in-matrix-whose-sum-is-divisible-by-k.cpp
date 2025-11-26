class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(m,vector<ll>(k+1,-1)));
        return fun(0,0,0,k,grid,dp);
    }

    int fun(int i,int j,ll val,int k,vector<vector<int>>&grid,vector<vector<vector<ll>>>&dp){

        if(i==grid.size()-1 && j==grid[0].size()-1){

            return ((val+grid[i][j])%k)==0;
        }

        if(i==grid.size() || j==grid[0].size())return 0;

        if(dp[i][j][val]!=-1)return dp[i][j][val];


        ll down = fun(i+1,j,(val+grid[i][j])%k,k,grid,dp);
        ll right = fun(i,j+1,(val+grid[i][j])%k,k,grid,dp);

        return dp[i][j][val]=(down+right)%mod;
    }
};