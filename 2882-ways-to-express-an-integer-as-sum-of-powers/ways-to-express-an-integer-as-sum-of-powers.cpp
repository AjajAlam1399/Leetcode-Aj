class Solution {
    using ll=long long;
    int dp[305][305];
    int mod=1e9+7;
public:
    int numberOfWays(int n, int x) {
        vector<int>vec;
        for(int i=1;i<=n;i++){
            vec.push_back(i);
        }
        memset(dp,-1,sizeof(dp));
        return fun(0,n,x,vec)%mod;
    }

    int fun(int ind,int target,int x , vector<int>&vec){

        if(ind==vec.size()){
            return target==0;
        }

        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        int not_taken=fun(ind+1,target,x,vec)%mod;
        int taken=0;
        ll powVal=1LL*pow(vec[ind],x);
        if(powVal<=target){
            taken=fun(ind+1,target-powVal,x,vec)%mod;
        }

        return dp[ind][target] = (taken+not_taken)%mod;
    }
};