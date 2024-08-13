class Solution {
    int maxele;
    using ll = long long;
    int mod = 1e9 + 7;

public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int maxel = *max_element(nums.begin(), nums.end());
        cout<<maxel<<endl;
        vector<vector<vector<ll>>> dp(
            n + 1, vector<vector<ll>>(maxel+2, vector<ll>(maxel+2, -1)));
            // return 0;
            return fun(0,0,maxel+1,nums,dp);
    }

    ll fun(int ind, int prev1, int prev2, vector<int>& nums,
           vector<vector<vector<ll>>>& dp) {

        if (ind == nums.size()) {
            return 1;
        }

        if (dp[ind][prev1][prev2] != -1)
            return dp[ind][prev1][prev2];

        ll ans = 0;

        for (int i = prev1; i <= nums[ind]; i++) {
            int num1 = i;
            int num2 = nums[ind] - num1;
            if (prev1 <= num1 && prev2 >= num2) {
                ans = (ans % mod + fun(ind + 1, num1, num2, nums, dp) % mod) %
                      mod;
            }
        }

        return dp[ind][prev1][prev2]=ans;
    }
};