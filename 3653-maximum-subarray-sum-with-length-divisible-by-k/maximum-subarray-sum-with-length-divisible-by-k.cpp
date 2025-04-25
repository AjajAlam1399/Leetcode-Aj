class Solution {
    using ll=long long;
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<ll,ll>map;
        ll sum=0;
        ll ans=LONG_MIN;
        for(ll i=1;i<=n;i++){
            sum+=(ll)nums[i-1];
            if(i>=k){
                ll mapVal=map[i%k];
                // cout<<sum<<","<<mapVal<<endl;
                ans=max(ans,sum-mapVal);
            }
            if(map.find(i%k)==map.end()){
                map[i%k]=sum;
            }
            else{
                map[i%k]=min(map[i%k],sum);
            }

            // cout<<ind<<","<<map[i%k]<<endl;
        }
        return ans;
    }
};