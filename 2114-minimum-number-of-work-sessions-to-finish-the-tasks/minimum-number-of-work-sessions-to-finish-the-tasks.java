class Solution {
    int workSession = 0;

    public int minSessions(int[] tasks, int sessionTime) {
        workSession = sessionTime;
        int n=tasks.length;
        int[][]dp=new int[sessionTime+1][1<<n+1];
        for(int i=0;i<=sessionTime;i++){
            Arrays.fill(dp[i],-1);
        }
        return 1+fun(-1,0,0,sessionTime,tasks,dp);
    }

    int fun(int ind,int level,int mask,int sessionTime,int[] tasks,int[][]dp){
        if(level==tasks.length){
            return 0;
        }
        if(dp[sessionTime][mask]!=-1){
            return dp[sessionTime][mask];
        }
        int ans=tasks.length;
        for(int i=0;i<tasks.length;i++){
            if((mask&(1<<i))>0){
                continue;
            }
            if(ind==-1||sessionTime>=tasks[i]){
                ans=Math.min(ans,fun(i,level+1,(mask|(1<<i)),sessionTime-tasks[i],tasks,dp));
            }
            else{
                ans=Math.min(ans,1+fun(i,level+1,(mask|1<<i),workSession-tasks[i],tasks,dp));
            }
        }
        return dp[sessionTime][mask]=ans;
    }
}