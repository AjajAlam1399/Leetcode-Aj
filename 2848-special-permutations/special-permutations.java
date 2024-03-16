class Solution {
    int mod=1000000000+7;
    public int specialPerm(int[] nums) {
        int n=nums.length;
        int [][]dp=new int[n+2][1<<n+1];

        for(int i=0;i<n+2;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(-1,0,0,nums,dp);
    }
    int fun(int ind,int level,int bit,int nums[],int[][]dp){
        if(level==nums.length){
            return 1;
        }
        if(dp[ind+1][bit]!=-1){
            return dp[ind+1][bit];
        }
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if((bit&(1<<i))>0){
                continue;
            }
            if(ind==-1 || nums[ind]%nums[i]==0|| nums[i]%nums[ind]==0){
                cnt+=fun(i,level+1,(bit|(1<<i)),nums,dp);
                cnt%=mod;
            }
        }
        return dp[ind+1][bit]= cnt;
    }
}