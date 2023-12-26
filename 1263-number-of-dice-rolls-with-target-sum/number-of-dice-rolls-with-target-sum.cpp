class Solution {
    int mod=1e9+7;
public:
    int numRollsToTarget(int n, int k, int target) {
       
       vector<vector<long long>>dp(n+1,vector<long long>(target+1,-1));
       return fun(0,0,target,n,k,dp);
    }

    int fun(int level,int curr,int target,int n,int k,vector<vector<long long>>&dp){

        if(level==n){
            return curr==target?1:0;
        }

        if(dp[level][curr]!=-1)return dp[level][curr];

        long long cnt=0;

        for(int i=1;i<=k;i++){
            if(curr+i<=target){
                cnt=(cnt%mod+fun(level+1,curr+i,target,n,k,dp)%mod)%mod;
            }
        }

        return dp[level][curr]= cnt%mod;
        
    }
};