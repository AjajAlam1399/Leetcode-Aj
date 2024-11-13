class Solution {
    using ll=long long;
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return fun(nums,upper)-fun(nums,lower-1);
    }
    ll fun(vector<int>&nums,int limit){
        int n=nums.size();
        int i=0,j=n-1;
        ll ans=0;
        while(i<j){
            ll sum=nums[i]+nums[j];
            if(sum<=limit){
                ans+=j-i;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};