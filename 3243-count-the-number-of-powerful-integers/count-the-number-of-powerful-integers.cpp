class Solution {
    using ll = long long;

    ll dp[16][2][2];

public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string str1 = to_string(start - 1);
        string str2 = to_string(finish);
        int suff = s.size();

        ll h = 0, l = 0;


        memset(dp, -1, sizeof(dp));
        if ((int)str2.size() > suff) {
            h = count(str2, limit, suff, s);
        }


        memset(dp, -1, sizeof(dp));
        if ((int)str1.size() > suff) {
            l = count(str1, limit, suff, s);
        }


        ll suffixNum = stoll(s);
        if (suffixNum >= start && suffixNum <= finish) {
            h++;
        }

        return h - l;
    }

private:
    ll count(string &bound, int maxDigit, int suffLen, const string &suffix) {
        return dpSolve(0, 1, 0, 0, bound, maxDigit, suffLen, suffix);
    }

    ll dpSolve(int ind, int tight, int isValid, ll prefix, string &bound, int maxDigit, int suffLen, const string &suffix) {
        int n = bound.size();
        if (ind == n - suffLen) {
            if (!isValid) return 0;


            string prefixStr = to_string(prefix);
            while ((int)prefixStr.size() < (n - suffLen)) {
                prefixStr = "0" + prefixStr;
            }
            string fullStr = prefixStr + suffix;


            return fullStr <= bound ? 1 : 0;
        }

        if (dp[ind][tight][isValid] != -1) {
            return dp[ind][tight][isValid];
        }

        int lim = tight ? (bound[ind] - '0') : 9;
        ll res = 0;

        for (int d = 0; d <= lim; d++) {
            int newTight = (tight && (d == lim));
            if (d == 0 && !isValid) {
                res += dpSolve(ind + 1, newTight, 0, 0, bound, maxDigit, suffLen, suffix);
            } else {
                if (d <= maxDigit) {
                    res += dpSolve(ind + 1, newTight, 1, prefix * 10 + d, bound, maxDigit, suffLen, suffix);
                }
            }
        }

        return dp[ind][tight][isValid] = res;
    }
};
