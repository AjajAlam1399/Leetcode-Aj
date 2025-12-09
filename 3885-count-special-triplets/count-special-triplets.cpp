class Solution {
    int mod=1e9+7;
    using ll=long long;
public:
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int ,int>total;

        for(int i=0;i<n;i++){
            total[nums[i]]++;
        }
        unordered_map<int,int>curr;

        ll ans=0;

        for(int i=0;i<n;i++){
            int num=nums[i];
            ll left=curr[num*2];
            ll right=total[num*2]-left;
            if(num==2*num)right--;
            // cout<<i<<","<<left<<","<<right<<endl;
            ans+=(left%mod*right%mod)%mod;
            curr[num]++;
        }

        return ans%mod;
    }
};