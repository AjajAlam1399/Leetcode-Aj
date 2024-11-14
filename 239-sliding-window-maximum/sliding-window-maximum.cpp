class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int>set;
        int n=nums.size(),s=0,e=0;
        vector<int>ans;
        while(e<n){
            set.insert(nums[e]);
            if(e-s+1==k){
                ans.push_back(*set.rbegin());
                set.erase(set.find(nums[s]));
                s++;
            }
            e++;
        }
        return ans;
    }
};