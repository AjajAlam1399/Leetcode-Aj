class Solution {
    using ll=long long ;
public:
    long long maximumTripletValue(vector<int>& nums) {

        int n=nums.size();
        vector<int>vec(n,-1);
        int maxV=nums[n-1];
        for(int i=n-2;i>=0;i--){
            vec[i]=maxV;
            maxV=max(maxV,nums[i]);
        }
        ll ans=0;
        ll leftM=nums[0];
        for(int i=1;i<n-1;i++){
            ll curr=(leftM-nums[i])*(ll)vec[i];
            ans=max(ans,curr);
            leftM=max(leftM,(ll)nums[i]);
        }

        return ans;
    }
};