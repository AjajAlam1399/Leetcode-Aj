class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> vec(32, 0);
        int ans = INT_MAX;
        int s = 0, e = 0;
        int orA = 0;
        while (e < n) {
            orA |= nums[e];
            for (int i = 31; i >= 0; i--) {
                int bit = ((nums[e]) & (1 << i));
                if (bit) {
                    vec[i]++;
                }
            }
            if (orA >= k) {
                while (e>=s && orA >= k) {
                    ans = min(ans, e - s + 1);
                    for (int i = 31; i >= 0; i--) {
                        int bit = ((nums[s]) & (1 << i));
                        if (bit) {
                            vec[i]--;
                            if (!vec[i]) {
                                orA ^= (1 << i);
                            }
                        }
                    }
                    s++;
                }
            }
            e++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};