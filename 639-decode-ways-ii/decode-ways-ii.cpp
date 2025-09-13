class Solution {
    const int MOD = 1e9 + 7;
    vector<long long> dp;

public:
    int numDecodings(string s) {
        int n = s.size();
        dp.resize(n + 1, -1);
        return helper(0, s);
    }

    long long helper(int i, string &s) {
        if (i == s.size()) return 1;
        if (dp[i] != -1) return dp[i];

        long long ways = 0;

        if (s[i] == '*') {
            ways = (ways + 9 * helper(i + 1, s)) % MOD;
        } else if (s[i] != '0') {
            ways = (ways + helper(i + 1, s)) % MOD;
        }

        if (i + 1 < s.size()) {
            if (s[i] == '*' && s[i + 1] == '*') {
                ways = (ways + 15 * helper(i + 2, s)) % MOD;
            } else if (s[i] == '*') {
                if (s[i + 1] >= '0' && s[i + 1] <= '6') {
                    ways = (ways + 2 * helper(i + 2, s)) % MOD;
                } else {
                    ways = (ways + helper(i + 2, s)) % MOD;
                }
            } else if (s[i + 1] == '*') {
                if (s[i] == '1') {
                    ways = (ways + 9 * helper(i + 2, s)) % MOD;
                } else if (s[i] == '2') {
                    ways = (ways + 6 * helper(i + 2, s)) % MOD;
                }
            } else {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (num >= 10 && num <= 26) {
                    ways = (ways + helper(i + 2, s)) % MOD;
                }
            }
        }

        return dp[i] = ways;
    }
};
