class Solution {
    int fun(int ind,int tar,vector<int>&A,vector<vector<int>>&dp){
        
        if(ind<0){
            return tar==0;
        }
        
        if(dp[ind][tar]!=-1){
            return dp[ind][tar];
        }
        
        int not_taken=fun(ind-1,tar,A,dp);
        
        int taken=0;
        
        if(tar>=A[ind]){
            
            taken=fun(ind-1,tar-A[ind],A,dp);
        }
        
        return dp[ind][tar]= taken+not_taken;
    }
public:
    int findTargetSumWays(vector<int>& A, int target) {
        int n=A.size();
        
        int s=0;
        
        for(int i=0;i<n;i++){
            s+=A[i];
        }
        
        if(s-target<0 || (s-target)%2!=0){
            return 0;
        }
        
        vector<vector<int>>dp(n,vector<int>((s-target)/2+1,-1));
        
        return fun(n-1,(s-target)/2,A,dp);
    }
};