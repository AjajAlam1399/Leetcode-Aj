class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> vec(101, 0);

        int i = 0, j = 0;
        vector<int> ans(n-k+1,0);
        int subcnt=0;
        while (j < n) {
            if (nums[j] >= 0) {
                vec[nums[j] + 50]++;
            } else {
                vec[50 - abs(nums[j])]++;
            }

            if (j - i + 1 == k) {
                int cnt = 0;
                for (int ind = 0; ind < 50; ind++) {
                    if (vec[ind]){
                        cnt+=vec[ind];
                        // cout<<ind<<","<<vec[ind]<<endl;
                    }
                    if (cnt >=x) {
                        ans[subcnt]=(-1 * (50 - ind));
                        break;
                    }
                }
                int val = nums[i];
                if (val >= 0) {
                    vec[val + 50]--;
                } else {
                    vec[50 - abs(val)]--;
                }
                i++;
                subcnt++;
            }
            j++;
        }

        return ans;
    }
};