class Solution {
    using ll=long long;
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        unordered_map<ll,ll>map;
        map[0]=1;
        int cnt=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]%modulo==k){
                cnt++;
            }
            ans+=map[(cnt-k+modulo)%modulo];
            map[cnt%modulo]++;
        }
        
        return ans;
    }
};