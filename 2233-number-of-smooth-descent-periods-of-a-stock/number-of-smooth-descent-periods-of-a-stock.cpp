class Solution {
    using ll = long long;
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll n = prices.size();
        ll s=0 ,e=1;
        ll ans=0;
        
        while(e<n){
            if(prices[e]-prices[e-1] == -1){
                e++;
            }
            else{
                ll len=e-s;
                // ll val = ((len)*(len+1))/2;
                // cout<<e<<"-"<<val<<endl;
                ans+=((len)*(len+1))/2;
                s=e;
                e++;
            }
        }

        if(s!=n){
            ll len=e-s;
            ans+=((len)*(len+1))/2;
        }
        return ans;
    }
};