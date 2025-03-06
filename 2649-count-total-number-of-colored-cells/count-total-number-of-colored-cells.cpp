class Solution {
    using ll=long long;
public:
    long long coloredCells(int n) {
        ll ans=1;
        for(ll i=1;i<n;i++){
            ans+=i*4;
        }
        return ans;
    }
};