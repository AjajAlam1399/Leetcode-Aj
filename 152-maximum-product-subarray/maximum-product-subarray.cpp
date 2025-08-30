class Solution {
    using ll=long long;
public:
    int maxProduct(vector<int>& nums) {
        ll pos=nums[0];
        ll neg=nums[0];
        ll ans=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(pos,neg);
            }
            pos=max((ll)nums[i],(ll)pos*nums[i]);
            neg=min((ll)nums[i],(ll)neg*nums[i]);
            ans=max(ans,pos);
        }

        return ans;
    }
};