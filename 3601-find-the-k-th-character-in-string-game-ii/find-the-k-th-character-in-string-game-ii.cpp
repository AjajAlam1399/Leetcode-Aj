class Solution {
    using ll = long long;

public:
    char kthCharacter(long long k, vector<int>& ops) {
        int cnt = 0;
        return dfs(ops.size() - 1, (long double)k, ops, cnt);
    }

    char dfs(int n, long double k, const vector<int>& ops, int& cnt) {
        if (n < 0) return 'a' + (cnt % 26);

        long double len = pow(2.0L, n + 1);
        long double mid = len / 2.0L;

        if (k > mid) {
            if (ops[n]) cnt++;
            return dfs(n - 1, k - mid, ops, cnt);
        } else {
            return dfs(n - 1, k, ops, cnt);
        }
    }
};
