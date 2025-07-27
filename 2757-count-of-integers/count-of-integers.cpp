class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        
    
        vector<vector<vector<ll>>>dp1(23,vector<vector<ll>>(2,
        vector<ll>(200,-1)));
        vector<vector<vector<ll>>>dp2(23,vector<vector<ll>>(2,
        vector<ll>(200,-1)));

        ll high = fun(0,true,0,num2,min_sum,max_sum,dp1)%mod;
        ll low = fun(0,true,0,num1,min_sum,max_sum,dp2)%mod;

        int digitSum=0;

        for(int i=0;i<num1.size();i++){
            digitSum+=num1[i]-'0';
        }

        if(digitSum>=min_sum && digitSum<=max_sum){
            low--;
        }
    
        return (high-low+mod)%mod;
    }

    ll fun(ll ind, ll tight,ll sum,string & str,ll min,ll max,vector<vector<vector<ll>>>&dp){

        if(ind==str.size()){
            return (sum>=min && sum<=max);
        }

        if(sum>max)return 0;

        if(dp[ind][tight][sum]!=-1){
            return dp[ind][tight][sum];
        }

        ll limit=tight ? str[ind]-'0':9;
        ll ans=0;
        for(ll d=0;d<=limit;d++){
            ll newTight = tight && d==limit;
            ans=(ans%mod + fun(ind+1,newTight,sum+d,str,min,max,dp)%mod)%mod;
        }
        return dp[ind][tight][sum]=ans%mod;
    }
};