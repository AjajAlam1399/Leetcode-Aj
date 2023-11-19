class Solution {
    using ll=long long int;
public:
    int reductionOperations(vector<int>& nums) {
        
        int n=nums.size();
        ll ans=0;

        int s=0;

        sort(nums.begin(),nums.end());

        while(s<n){
            while(s+1<n && nums[s]==nums[s+1]){
                s++;
            }
            if(n-1-s>0){
                ans+=n-1-s;
            }
            s++;
        }

        return ans;
    }
};