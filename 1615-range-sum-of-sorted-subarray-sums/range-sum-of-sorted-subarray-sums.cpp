class Solution {
    using ll=long long;
    int mod=1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        
        vector<ll>vec;

        for(int i=0;i<n;i++){
            ll sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());
        ll ans=0;
        for(int i=left-1;i<=right-1;i++){
            ans=(ans%mod+vec[i]%mod)%mod;

        }
        return ans;
    }
};