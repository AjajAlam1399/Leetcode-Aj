class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<ll>vec(26,0);

        for(int i=0;i<s.size();i++){
            vec[s[i]-'a']++;
        }

        for(int i=0;i<t;i++){
            vector<ll>temp(26,0);
            for(int j=0;j<25;j++){
                ll cnt=vec[j];
                temp[j+1]+=cnt;
                temp[j+1]%=mod;
            }
            ll cnt=vec[25];
            temp[0]+=cnt;
            temp[0]%=mod;
            temp[1]+=cnt;
            temp[1]%=mod;
            vec=temp;
        }

        ll ans=0;

        for(int i=0;i<26;i++){
            ans+=vec[i];
            ans%=mod;
        }

        return ans;
    }
};