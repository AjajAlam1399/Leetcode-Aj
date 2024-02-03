class Solution {
    int n;
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        n=arr.size();
        vector<int>dp(n,-1);
        return fun(0,arr,k,dp);
    }

    int fun(int ind,vector<int>&arr,int k,vector<int>&dp){
        if(ind==arr.size()){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int currmax=INT_MIN;
        int ans=0;
        for(int i=ind;i<min(n,ind+k);i++){
            currmax=max(currmax,arr[i]);
            int sum=currmax*(i-ind+1)+fun(i+1,arr,k,dp);
            ans=max(ans,sum);
        }

        return dp[ind]= ans;
    }
};