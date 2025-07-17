class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 1;

        for (int targetMod = 0; targetMod < k; ++targetMod) {
            unordered_map<int, int> dp;
            for (int num : nums) {
                int needed = (targetMod - num % k + k) % k;
                int best = dp.count(needed) ? dp[needed] + 1 : 1;
                dp[num % k] = max(dp[num % k], best);
                ans = max(ans, dp[num % k]);
            }
        }

        return ans;
    }
};
