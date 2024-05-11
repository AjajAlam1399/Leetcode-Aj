class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int i = -1, j = -1;
        vector<int> vec(32, 0);
        int curor = 0;
        int len = INT_MAX;
        while (true) {
            bool f1 = false;
            bool f2 = false;
            while (i < n - 1) {
                f1 = true;
                i++;
                int num = nums[i];
                for (int b = 0; b < 32; b++) {
                    int bit = ((num) & (1 << b));
                    if (bit)
                        vec[b]++;
                }
                curor |= num;
                if (curor >= k) {
                    break;
                }
            }
            while (j < i) {
                // cout << curor << " " << i << " " << j << endl;
                f2 = true;
                if (curor >= k) {
                    len = min(len, i - j);
                }
                j++;
                int num = nums[j];
                for (int b = 0; b < 32; b++) {
                    int bit = ((num) & (1 << b));
                    if (bit) {
                        if (vec[b] == 1) {
                            curor -= (1 << b);
                        }
                        vec[b]--;
                    }
                }
                if (curor < k)
                        break;
            }
            if (!f1 && !f2)
                break;
        }
        return len == INT_MAX ? -1 : len;
    }
};