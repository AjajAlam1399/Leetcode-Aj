class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans=fun(0,target,nums,dp);
        return ans<0?-1:ans;
    }
    int fun(int curr,int target,vector<int>&nums,vector<vector<int>>&dp){

        if(curr==nums.size()){
            if(target==0){
                return 0;
            }
            return -100000;
        }
        if(dp[curr][target]!=-1){
            return dp[curr][target];
        }

        int not_taken=fun(curr+1,target,nums,dp);
        int taken=-100000;
        if(target-nums[curr]>=0){
                taken=1+fun(curr+1, target-nums[curr],nums,dp);
        }

        return dp[curr][target]=max(taken,not_taken);
    }
};