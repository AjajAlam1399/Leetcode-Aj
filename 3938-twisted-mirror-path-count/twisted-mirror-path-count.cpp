class Solution {
    using ll=long long;
    ll dp[501][501][3];
    int mod=1e9+7;
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        memset(dp,-1,sizeof dp);
        return fun(0,0,-1,grid);
    }

    ll fun(int i,int j,int dir,vector<vector<int>>& grid){

        if(j==grid[0].size()-1 && grid.size()-1==i){
            return 1;
        }

        if(j==grid[0].size() || grid.size()==i){
            return 0;
        }

        if(dp[i][j][dir+1]!=-1)return dp[i][j][dir+1];

        if(grid[i][j] && dir!=-1){
            if(dir==1){
                return dp[i][j][dir+1]=fun(i,j+1,0,grid)%mod;
            }
            else{
                return dp[i][j][dir+1]=fun(i+1,j,1,grid)%mod;
            }
        }
        else {
            ll  down=0,right=0;
            down = fun(i+1,j,1,grid)%mod;
            right = fun(i,j+1,0,grid)%mod;
            return dp[i][j][dir+1]=(down+right)%mod;
        }
    }
};