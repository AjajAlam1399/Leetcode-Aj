class Solution {
private:
    vector<bool> isPrime;
    void primeFunction() {
        for (int i = 2; i <= 1e3; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= 1e3; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    Solution() {
        isPrime.resize(1e3 + 1, true);
        primeFunction();
    }
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                continue;
            }
            int num = nums[i];
            bool flag = false;
            for (int j = 2; j <= num; j++) {
                if (isPrime[j] && num - j > 0 && nums[i + 1] > num - j) {
                    nums[i] = num - j;
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return false;
        }
        return true;
    }
};