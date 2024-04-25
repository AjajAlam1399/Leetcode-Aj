class Solution {
    using ll=long long;
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        vector<vector<ll>>dp(n,vector<ll>(27,-1));
        return fun(0,-1,s,k,dp);
    }

    ll fun(int ind,int prev,string &s,int k,vector<vector<ll>>&dp){

        if(ind==s.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        ll not_taken=fun(ind+1,prev,s,k,dp);
        ll taken=0;
        if(prev==-1 || abs((s[ind]-'a')-prev)<=k){
            taken=1+fun(ind+1,s[ind]-'a',s,k,dp);
        }
        return dp[ind][prev+1]=max(taken,not_taken);

    }
};