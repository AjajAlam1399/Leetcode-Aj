class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return fun(nums,right)-fun(nums,left-1);
    }
    long fun(vector<int>&nums,int val){
        int i=0,j=0,n=nums.size();
        long ans=0;
        while(j<n){
            if(nums[j]<=val){
                j++;
            }
            else{
                long len=j-i;
                ans+=((len)*(len+1))/2;
                j++;
                i=j;
            }
        }
        long len=j-i;
        ans+=((len)*(len+1))/2;
        return ans;
        
    }
};