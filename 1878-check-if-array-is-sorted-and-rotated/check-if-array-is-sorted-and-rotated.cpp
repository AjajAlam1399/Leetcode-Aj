class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ind = i - 1;
                break;
            }
        }
        cout << ind << endl;
        if (ind == -1)
            return true;
        for (int i = 1; i <= ind; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        for (int i = ind + 2; i < n; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        if (nums[0] < nums[n - 1])
            return false;
        return true;
    }
};