class Solution {
    using ll=long long;
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<ll>>dp(n,vector<ll>(n,-1));
        int total=accumulate(nums.begin(),nums.end(),0);
         ll curr=fun(0,nums.size()-1,1,nums,dp);
         return curr>=total-curr;
    }

    ll fun(int i,int j,int turn,vector<int>&ans,vector<vector<ll>>&dp){



        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(turn){
            return dp[i][j]=max(ans[i]+fun(i+1,j,0,ans,dp),ans[j]+fun(i,j-1,0,ans,dp));
        }
        else{
           return dp[i][j]= min(fun(i+1,j,1,ans,dp),fun(i,j-1,1,ans,dp));
        }
    }

};