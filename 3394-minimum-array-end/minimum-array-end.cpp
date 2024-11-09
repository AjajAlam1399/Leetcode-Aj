class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> vec;

        while (x) {
            int bit = x & (1 << 0);
            vec.push_back(bit);
            x = x >> 1;
        }
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++) {
            if (!vec[i]) {
                cnt++;
            }
        }
        while ((1 << cnt) < n) {
            vec.push_back(0);
            cnt++;
        }
        for (int i = vec.size() - 1; i >= 0; i--) {
            if (vec[i] == 0) {
                int tp = 1 << (cnt - 1);
                if (tp < n) {
                    vec[i] = 1;
                    n -= tp;
                }
                cnt--;
            }
        }
        long long ans = 0;
        for (long long i = 0; i < vec.size(); i++) {
            if (vec[i]) {
                ans += pow(2,i);
            }
        }
        return ans;
    }
};