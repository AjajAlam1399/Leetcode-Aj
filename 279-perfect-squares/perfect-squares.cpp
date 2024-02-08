class Solution {
public:
    int numSquares(int n) {
        int len=sqrt(n);
        vector<int>vec;
        for(int i=1;i<=len;i++){
            vec.push_back(i*i);
        }
        vector<vector<int>>dp(vec.size(),vector<int>(n+1,-1));
        return fun(vec.size()-1,n,vec,dp);
    }

    int fun(int ind,int tar,vector<int>&vec,vector<vector<int>>&dp){

        if(ind==-1){
            if(tar==0){
                return 0;
            }
            return 1e7;
        }
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        int not_taken=fun(ind-1,tar,vec,dp);
        int taken=1e7;
        if(tar>=vec[ind]){
            taken=1+fun(ind,tar-vec[ind],vec,dp);
        }

        return dp[ind][tar]=min(taken,not_taken);
    }
};