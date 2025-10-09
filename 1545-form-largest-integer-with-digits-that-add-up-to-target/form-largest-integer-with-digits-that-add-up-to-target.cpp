class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> dp(target + 1, "#");
        dp[0] = "";

        for (int t = 1; t <= target; ++t) {
            for (int d = 1; d <= 9; d++) {
                int c = cost[d - 1];
                if (t >= c && dp[t - c] != "#") {
                    string cand = dp[t - c] + char('0' + d);
                    if (dp[t] == "#" ||
                        cand.size() > dp[t].size() ||
                        (cand.size() == dp[t].size() && cand > dp[t])) {
                        dp[t] = cand;
                    }
                }
            }
        }
        return dp[target] == "#" ? "0" : dp[target];
    }
};
