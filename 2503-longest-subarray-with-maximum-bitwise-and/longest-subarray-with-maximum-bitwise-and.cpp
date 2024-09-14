class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxel = *max_element(nums.begin(), nums.end());

        int s = 0, e = 0, n = nums.size();
        int ans = 1;
        while (e < n) {
            if (nums[e] == maxel) {
                e++;
            } else {
                if (nums[s] == maxel) {
                    ans = max(ans, e - s);
                } else {
                    ans = max(ans, e - s - 1);
                }
                s = e;
                e++;
            }
        }
        if (nums[s] == maxel) {
            ans = max(ans, e - s);
        } else {
            ans = max(ans, e - s - 1);
        }
        return ans;
    }
};