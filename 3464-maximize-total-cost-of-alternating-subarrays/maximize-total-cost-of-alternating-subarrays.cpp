class Solution {
    using ll=long long ;
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<vector<ll>>>dp(n,vector<vector<ll>>(2,vector<ll>(2,-1)));
        return fun(0,0,0,nums,dp);
    }

    ll fun(int ind,int prev,int sign,vector<int>& nums,vector<vector<vector<ll>>>&dp){

        if(ind==nums.size())return 0;

        ll newa=-1e9;
        ll olda=-1e9;

        if(dp[ind][prev][sign]!=-1)return dp[ind][prev][sign];

        if(prev){
            if(sign){
                olda=-nums[ind]+fun(ind+1,1,0,nums,dp);
            }
            else{
                olda=nums[ind]+fun(ind+1,1,1,nums,dp);
            }
            newa=nums[ind]+fun(ind+1,1,1,nums,dp);
        }
        else{
            newa=nums[ind]+fun(ind+1,1,1,nums,dp);
        }
        return dp[ind][prev][sign]=max(newa,olda);
    }
};