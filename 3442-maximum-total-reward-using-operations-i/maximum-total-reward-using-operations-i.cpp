class Solution {
    using ll=long long ;
public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());

        // int sum=accumulate(rewardValues.begin(),rewardValues.end(),0);

        vector<vector<int>>dp(rewardValues.size(),vector<int>(1e4,-1));
        
        return fun(0,0,rewardValues,dp);
    }

    ll fun(int ind,int sum,vector<int>& rewardValues,vector<vector<int>>&dp){

        if(ind==rewardValues.size())return 0;

        if(dp[ind][sum]!=-1)return -1;

        ll not_taken=fun(ind+1,sum,rewardValues,dp);
        ll taken=0;
        if(sum<rewardValues[ind]){
            taken=rewardValues[ind]+fun(ind+1,sum+rewardValues[ind],rewardValues,dp);
        }

        return dp[ind][sum]=max(not_taken,taken);
    }
};