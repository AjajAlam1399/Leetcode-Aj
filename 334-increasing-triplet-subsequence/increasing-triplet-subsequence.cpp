class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n);
        vec[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            vec[i]=max(vec[i+1],nums[i]);
        }
        int minval=nums[0];
        for(int i=1;i<n;i++){
            if(minval<nums[i] && vec[i]>nums[i])return true;
            minval=min(minval,nums[i]);
        }
        return false;
    }
};