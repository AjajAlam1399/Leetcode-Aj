class Solution {
    using ll=long long;
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        ll n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]%=k;
        }
        vector<ll>ans(k);
        
        for(int i=0;i<k;i++){
            vector<vector<ll>>dp(n,vector<ll>(k+1,-1));
            ans[i]=fun(0,-1,nums,i,k,dp);
        }
        return ans;
    }

    ll fun(int ind,ll val,vector<int>& nums,int req,int k,vector<vector<ll>>&dp){
        if(ind==nums.size()){
            return 0;
        }
        if(dp[ind][val+1]!=-1){
            return dp[ind][val+1];
        }
        ll start=0,not_start=0;
        if(val==-1){
            if(req==nums[ind]){
                start=1+fun(ind+1,nums[ind],nums,req,k,dp);
            }
            else{
                start=fun(ind+1,nums[ind],nums,req,k,dp);
            }
            not_start=fun(ind+1,val,nums,req,k,dp);
        }
        else{
            ll mod=(val*nums[ind])%k;
            if(mod==req){
                start=1+fun(ind+1,mod,nums,req,k,dp);
            }
            else{
                start=fun(ind+1,mod,nums,req,k,dp);
            }
        }
        
        return dp[ind][val+1]=start+not_start;
    }
};