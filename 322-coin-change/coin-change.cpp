class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=fun(0,coins,amount,dp);

        return ans>=1e5?-1:ans;
    }

    int fun(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){

        if(ind==coins.size()){
            return amount==0?0:1e5;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int not_taken=fun(ind+1,coins,amount,dp);
        int taken=1e5;

        if(amount-coins[ind]>=0){
            taken=1+fun(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(taken,not_taken);
    }
};