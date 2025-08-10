class Solution {
    using ll=long long ;
public:
    long long maxSumTrionic(vector<int>& nums) {
        ll n=nums.size();
        vector<vector<ll>>dp(4,vector<ll>(n,-1e15));
        dp[0][0]=nums[0];
        ll ans=LONG_MIN;
        for(int i=1;i<n;i++){
            dp[0][i]=nums[i];
            if(nums[i]>nums[i-1]){
                dp[1][i]=max(dp[0][i-1]+nums[i],dp[1][i-1]+nums[i]);
            }
            if(nums[i]<nums[i-1]){
                dp[2][i]=max(dp[1][i-1]+nums[i],dp[2][i-1]+nums[i]);
            }
            if(nums[i]>nums[i-1]){
                dp[3][i]=max(dp[2][i-1]+nums[i],dp[3][i-1]+nums[i]);
            }
            ans=max(ans,dp[3][i]);
        }
        return ans;
    }
};