class Solution {
    int dp[];
    public int minCut(String s) {
        int n=s.length();
        dp = new int [n];

        Arrays.fill(dp,-1);

        return fun(0,s)-1;
    }

    int fun(int ind , String s){

        if(ind==s.length()) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int ans=Integer.MAX_VALUE;
        for(int j=ind;j<s.length();j++){
            if(isPlanidrome(ind,j,s)){
                ans = Math.min(ans,1+fun(j+1,s));
            }
        }

        return dp[ind]  = ans;
    }

    boolean isPlanidrome(int i, int j, String str){

        int s=i,e=j;

        while(s<=e){
            if(str.charAt(s)!=str.charAt(e))return false;
            s++;
            e--;
        }
        return true;
    }
}