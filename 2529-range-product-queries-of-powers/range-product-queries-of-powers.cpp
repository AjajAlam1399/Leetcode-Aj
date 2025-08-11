class Solution {
    using ll=long long;
    ll mod=1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<ll>power;
        ll temp=n;
        for(int i=0;i<32;i++){
            int bit=(temp)&(1<<i);
            if(bit){
                power.push_back(1<<i);
            }
        }

        vector<int>ans;

        for(auto it :queries){
            ll product=1;
            for(int i=it[0];i<=it[1];i++){
                product= (product%mod*power[i]%mod)%mod;
                
            }
            ans.push_back(product);
        }

        return ans;
    }
};