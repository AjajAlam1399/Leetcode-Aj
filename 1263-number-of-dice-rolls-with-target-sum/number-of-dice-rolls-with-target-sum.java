class Solution {
    private int mod=1000000000+7;
    public int numRollsToTarget(int n, int k, int target) {
        int[][]dp=new int[n+1][target+1];
        for(int i=0;i<=n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(0,0,target,n,k,dp);
    }
    int fun(int level,int curr,int target,int n,int k,int [][]dp){

        if(level==n){
            return curr==target?1:0;
        }

        if(dp[level][curr]!=-1)return dp[level][curr];

        int cnt=0;

        for(int i=1;i<=k;i++){
            if(curr+i<=target){
                cnt=(cnt%mod+fun(level+1,curr+i,target,n,k,dp)%mod)%mod;
            }
        }

        return dp[level][curr]= cnt%mod;
        
    }
}