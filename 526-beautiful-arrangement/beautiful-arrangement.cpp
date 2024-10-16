class Solution {
    using ll=long long ;
public:
    int countArrangement(int n) {
        vector<vector<ll>>dp(n+1,vector<ll>(1<<(n+1),-1));
        return fun(1,0,n,dp);
    }

    ll fun(int ind,int bitmask,int n,vector<vector<ll>>&dp){
        if(ind==n+1){
            return 1;
        }
        if(dp[ind][bitmask]!=-1)return dp[ind][bitmask];
        ll cnt=0;
        for(int i=1;i<=n;i++){
            if(i%ind==0 || ind%i==0){
                int bit=(bitmask&(1<<i));
                if(!bit){
                    cnt+=fun(ind+1,(bitmask|(1<<i)),n,dp);
                }
            }
        }
        return  dp[ind][bitmask]=cnt;
    }
};