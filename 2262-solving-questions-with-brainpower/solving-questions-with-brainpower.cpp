class Solution {
    using ll=long long ;
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<ll>dp(n+1,-1);
        return fun(0,questions,dp);
    }
    ll fun(int ind,vector<vector<int>>& questions
    ,vector<ll>&dp){
        if(ind>=questions.size()){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        ll not_taken= fun(ind+1,questions,dp);
        ll taken=questions[ind][0]+fun(ind+1+questions[ind][1],questions,dp);

        return dp[ind]=max(not_taken,taken);
    }
};