
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long m = 0, c = 0, MOD = 1e9+7;
        for(int i = 0; i < arr.size(); i++) {
            c += arr[i];
            m = max(m, c);
            if(c < 0) {
                c = 0;
            }
        }
        if(k == 1) {
            return m % MOD;
        } else {
            vector<int> p = arr;
            p.insert(p.end(), arr.begin(), arr.end());
            m = 0, c = 0;
            for(int i = 0; i < p.size(); i++) {
                c += p[i];
                m = max(m, c);
                if(c < 0) {
                    c = 0;
                }
            }
           long long sum = 0;
        for (auto& num : arr) {
            sum += num;
        }
        long long o = m + ((k - 2) * sum);
        return (sum < 0) ? m % MOD : o % MOD;

        }
    }
};