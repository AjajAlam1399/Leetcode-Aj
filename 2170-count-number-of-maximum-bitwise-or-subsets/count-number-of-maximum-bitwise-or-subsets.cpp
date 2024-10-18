class Solution {
    using ll=long long;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        ll maxOr=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            maxOr|=nums[i];
        }
        ll ans=0;
        vector<vector<ll>>dp(n+1,vector<ll>(maxOr+1,-1));
       return  fun(0,0,maxOr,nums,dp);
    }

    ll fun(int ind,int currOr,ll &maxOr,vector<int>& nums,vector<vector<ll>>&dp){
        if(ind==nums.size()){
            return currOr==maxOr;
        }
        if(dp[ind][currOr]!=-1)return dp[ind][currOr];
        ll taken=fun(ind+1,currOr,maxOr,nums,dp);
        ll not_taken=fun(ind+1,currOr|nums[ind],maxOr,nums,dp);

        return dp[ind][currOr]=taken+not_taken;
    }
};