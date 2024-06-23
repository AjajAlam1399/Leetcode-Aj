class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> set;
        int ans = 1;
        int n = nums.size(), s = 0, e = 1;
        set.insert(nums[0]);

        while (e < n) {
            set.insert(nums[e]);
            int first = *set.begin();
            int last = *(set.rbegin());
            // cout<<last<<endl;
            if (abs(last - first) <= limit) {
                ans = max(ans,e-s+1);
                // cout<<ans<<" "<<s<<"-"<<e<<endl;
            } else {
                while (abs(last - first) > limit) {
                    set.erase(set.find(nums[s]));
                    s++;
                     first = *set.begin();
                     last = *(set.rbegin());
                }
            }
            e++;
        }
        return ans;
    }
};