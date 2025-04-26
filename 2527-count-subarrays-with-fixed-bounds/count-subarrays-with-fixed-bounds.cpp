class Solution {
    using ll=long long;
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll ans=0;
        ll s=0,mni=-1,mxi=-1;

        for(ll i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                s=i+1;
                mni=-1,mxi=-1;
            }
            else{
                if(nums[i]==minK){
                    mni=i;
                }
                if(nums[i]==maxK){
                    mxi=i;
                }
            }
            if(mni!=-1 && mxi!=-1){
                ans+=min(mni,mxi)-s+1;
            }
        }
        return ans;
    }
};