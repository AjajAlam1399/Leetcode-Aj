class Solution {
    using ll = long long;

public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();

        int maxele = *max_element(nums.begin(), nums.end());

        ll ans = 0;

        for (int div = 1; maxele / div > 0; div *= 10) {

            vector<int> vec(10, 0);
            for (int i = 0; i < n; i++) {
                vec[(nums[i] / div) % 10]++;
            }
            // for(int i=0;i<10;i++){
            //     cout<<i<<"-"<<vec[i]<<"|";
            // }

            for (int i = 0; i < 10; i++) {
                ll cnt1 = vec[i];
                for (int j = i + 1; j < 10; j++) {
                    if (vec[j] != 0) {
                        ll cnt2 = vec[j];
                        ans += cnt1 * cnt2;
                    }
                }
            }
        }
        return ans;
    }
};