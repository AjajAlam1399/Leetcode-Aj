class Solution {
    int dp[40005][4];
public:
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,nums);
    }

    int fun(int ind,int div,vector<int>&nums){

        if(ind==nums.size()){
            if(div==0)return 0;
            return -1e9;
        }

        if(dp[ind][div]!=-1)return dp[ind][div];

        int not_taken=fun(ind+1,div,nums);
        int taken=nums[ind]+fun(ind+1,(div+nums[ind])%3,nums);

        return  dp[ind][div]=max(taken,not_taken);
    }
};