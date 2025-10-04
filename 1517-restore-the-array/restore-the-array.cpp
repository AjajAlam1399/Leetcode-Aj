class Solution {
    using ll=long long;
    int mod=1e9+7;
    int dp[100000+5];
public:
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return fun(0,s,k);
    }

    ll fun(int ind,string &s, int k){

        if(ind==s.size())return 1;

        if(dp[ind]!=-1)return dp[ind];

        ll ans=0;
        ll curr=0;

        for(int i=ind;i<s.size();i++){
            curr= curr *10 + s[i]-'0';

            if(curr==0 || curr>k){
                break;
            }
            ans=(ans%mod+fun(i+1,s,k)%mod)%mod;
        }

        return dp[ind]=ans;
    }
};