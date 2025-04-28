class Solution {
    using ll=long long;
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        ll ans = 0, sum = 0;
        int j = 0, n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            
            while (j <= i && sum * (i - j + 1) >= k) {
                sum -= nums[j];
                ++j;
            }
            
            ans += (i - j + 1);
        }
        
        return ans;
    }
};
