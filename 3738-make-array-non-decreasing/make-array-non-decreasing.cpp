class Solution {
    using ll=long long;
public:
    int maximumPossibleSize(vector<int>& nums) {
        ll ans=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=prev){
                ans++;
            }
            prev=max(prev,nums[i]);
        }
        return ans;
    }
};