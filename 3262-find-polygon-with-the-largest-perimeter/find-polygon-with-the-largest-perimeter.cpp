class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      long long prev=0;
      long long ans=-1;
      for(int i=0;i<nums.size();i++){
          if(prev>nums[i]){
              ans=max(ans,prev+nums[i]);
          }
          prev+=nums[i];
      }
      return ans;
    }
};