class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vec(m,vector<int>(10,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec[i][grid[j][i]]++;
            }
        }
        vector<vector<int>>dp(m,vector<int>(12,-1));
        return fun(0,-1,vec,n,dp);
    }

    int fun(int ind,int prev,vector<vector<int>>&vec,int n,vector<vector<int>>&dp){

        if(ind==vec.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        int ans=1e7;

        for(int i=0;i<=9;i++){
            int currans=1e7;
            if(prev!=i){
                currans=n-vec[ind][i]+fun(ind+1,i,vec,n,dp);
            }
            ans=min(ans,currans);
        }
        return dp[ind][prev+1]=ans;
    }
};