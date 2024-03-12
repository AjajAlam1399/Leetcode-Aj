
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
            
            m = 0, c = 0;
            for(int i = 0; i < 2*arr.size(); i++) {
                c += arr[i%arr.size()];
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