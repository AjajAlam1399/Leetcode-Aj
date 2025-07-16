class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int n=nums.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(3,-1)));
        int ans1= fun(0,-1,nums,1,dp);
        int ans2=fun(0,-1,nums,0,dp);

        return max(ans1,ans2);
    }

    int fun(int ind,int mod,vector<int>&nums,int modVal,vector<vector<vector<int>>>&dp){

        if(ind==nums.size())return 0;


        if(dp[modVal][ind][mod+1]!=-1){
            return dp[modVal][ind][mod+1];
        }

        int not_taken=fun(ind+1,mod,nums,modVal,dp);

        int taken=0;

        if(mod==-1){
            taken=1+fun(ind+1,nums[ind]%2,nums,modVal,dp);
        }
        else if((mod+nums[ind])%2==modVal){
            taken=1+fun(ind+1,nums[ind]%2,nums,modVal,dp);
        }

        return dp[modVal][ind][mod+1]=max(taken,not_taken);
    }
};