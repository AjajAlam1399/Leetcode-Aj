class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int numOfArrays(int n, int m, int k) {
        if(k==0)return 0;
        vector<vector<vector<ll>>>dp(n+1,vector<vector<ll>>(m+2,vector<ll>(k+1,-1)));
        return fun(0,-1,0,n,m,k,dp);
    }
    ll fun(int ind,int prev,int cnt,int n,int m,int k,vector<vector<vector<ll>>>&dp){

        if(ind==n){
            return cnt==k;
        }
        if(dp[ind][prev+1][cnt]!=-1)return dp[ind][prev+1][cnt];
        ll ans=0;
        for(int i=1;i<=m;i++){
            if(prev==-1){
                ans+=fun(ind+1,i,cnt+1,n,m,k,dp);
                ans%=mod;
            }
            else{
                if(i<=prev){
                    ans+=fun(ind+1,prev,cnt,n,m,k,dp);
                    ans%=mod;
                }
                else if(i>prev && cnt+1<=k){
                    ans+=fun(ind+1,i,cnt+1,n,m,k,dp);
                    ans%=mod;
                }
            }
        }
        return dp[ind][prev+1][cnt]=ans%mod;
    }
};