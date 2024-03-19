class Solution {
public:
    int countVowelStrings(int n) {
        string s="aeiou";
        vector<vector<int>>dp(n+1,vector<int>(27,-1));
        return fun(n,-1,s,dp);
    }

    int fun(int n,int prev,string &s,vector<vector<int>>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n][prev+1]!=-1){
            return dp[n][prev+1];
        }
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(prev==-1 || prev<=s[i]-'a'){
                cnt+=fun(n-1,s[i]-'a',s,dp);
            }
        }
        return dp[n][prev+1]=cnt;
    }
};