class Solution {
    using ll=long long;
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        vector<vector<ll>>dp(n+2,vector<ll>(1<<n+2,-1));
        return fun(0,0,arr,dp);
    }

    int fun(int ind,int bitmask,vector<int>& arr,
    vector<vector<ll>>&dp){
        if(ind==arr.size()){
            return 0;
        }
        if(dp[ind][bitmask]!=-1)return dp[ind][bitmask];
        ll ans=0;
        for(int i=ind;i<arr.size();i++){
            ll cnt=0;
            int val=arr[i];
            bitmask=((bitmask)|(1<<val));
            int cmpVal=1<<(i+1);
            cmpVal--;
            if(bitmask==cmpVal){
                cnt=1+fun(i+1,bitmask,arr,dp);
            }
            ans=max(ans,cnt);
        }
        return dp[ind][bitmask]=ans;
    }
};