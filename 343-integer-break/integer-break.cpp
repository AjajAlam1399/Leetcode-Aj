class Solution {
public:
    int integerBreak(int n) {
        vector<int>vec;
        for(int i=1;i<n;i++){
            vec.push_back(i);
        }
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(0,n,vec,dp);
    }
    int fun(int ind,int target,vector<int>&vec,vector<vector<int>>&dp){

        if(ind==vec.size()){
            if(!target)return 1;
            return -1;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        int not_taken=fun(ind+1,target,vec,dp);
        int taken=1;

        if(target-vec[ind]>=0){
            taken=vec[ind]*fun(ind,target-vec[ind],vec,dp);
        }

        return max(taken,not_taken);
    }
};