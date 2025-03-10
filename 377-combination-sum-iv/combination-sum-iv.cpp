class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1,-1);
        return fun(target,nums,dp);
    }

    int fun(int target,vector<int>&nums,vector<int>&dp){

        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(target-nums[i]>=0){
                ans+=fun(target-nums[i],nums,dp);
            }
        }

        return dp[target]=ans;
    }
};