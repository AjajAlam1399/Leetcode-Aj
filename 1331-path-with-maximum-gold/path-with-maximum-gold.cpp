class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visted(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,fun(i,j,grid,visted));
                }
            }
        }
        return ans;
    }

    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>&visted){
        visted[i][j]=true;
        int ans=grid[i][j];

        if(i-1>=0 && !visted[i-1][j] && grid[i-1][j]){
            ans=max(ans,grid[i][j]+fun(i-1,j,grid,visted));
        }
        if(j-1>=0 && !visted[i][j-1] && grid[i][j-1]){
             ans=max(ans,grid[i][j]+fun(i,j-1,grid,visted));
        }
        if(i+1<grid.size() && !visted[i+1][j] && grid[i+1][j]){
             ans=max(ans,grid[i][j]+fun(i+1,j,grid,visted));
        }
        if(j+1<grid[0].size() && !visted[i][j+1] && grid[i][j+1]){
             ans=max(ans,grid[i][j]+fun(i,j+1,grid,visted));
        }
        visted[i][j]=false;
        return ans;

    }
};