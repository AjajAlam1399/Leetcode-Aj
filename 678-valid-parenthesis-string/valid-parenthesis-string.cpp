class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return fun(0,0,s,dp);
    }

    bool fun(int ind,int cnt,string &s,vector<vector<int>>&dp){

        if(ind==s.size()){
            return cnt==0;
        }
        if(dp[ind][cnt]!=-1){
            return dp[ind][cnt];
        }

        bool ans=0;

        if(s[ind]=='('){
            ans=fun(ind+1,cnt+1,s,dp);
        }
        else if(s[ind]==')'){
            if(cnt){
                ans=fun(ind+1,cnt-1,s,dp);
            }
        }
        else if(s[ind]=='*'){
            if(cnt){
                ans|=fun(ind+1,cnt-1,s,dp);
            }
            ans|=fun(ind+1,cnt+1,s,dp);
            ans|=fun(ind+1,cnt,s,dp);
        }
        return dp[ind][cnt]=ans;
    }
};