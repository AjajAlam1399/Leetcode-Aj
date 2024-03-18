class Solution {
    public int longestIdealString(String s, int k) {
        int n=s.length();
        int[][] dp=new int[n][27];
        for(int i=0;i<n;i++){
            Arrays.fill(dp[i],-1);
        }
        return fun(-1,0,s,k,dp);
    }

    int fun(int prev,int curr,String s,int k,int[][] dp){

        if(curr==s.length()){
            return 0;
        }

        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }

        int not_taken=fun(prev,curr+1,s,k,dp);
        int taken=0;
        if(prev==-1||Math.abs(prev-(s.charAt(curr)-'a'))<=k){
            taken=1+fun(s.charAt(curr)-'a',curr+1,s,k,dp);
        }
        return dp[curr][prev+1]=Math.max(taken,not_taken);
    }
}