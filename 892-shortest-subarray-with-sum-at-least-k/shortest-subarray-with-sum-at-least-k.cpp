class Solution {
    using ll = long long;

public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        ll sum = 0;
        int ans = INT_MAX;
        deque<int> dq;
        vector<ll> arr(n);
        sum = 0;
        int j = 0;
        while (j < n) {
            sum += nums[j];
            arr[j] = sum;
            if (sum >= k) {
                ans = min(ans, j + 1);
            }
            while (!dq.empty() && arr[j] - arr[dq.front()] >= k) {
                int len = j - dq.front();
                ans = min(ans, len);
                dq.pop_front();
            }

            while (!dq.empty() && arr[dq.back()] >= arr[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};