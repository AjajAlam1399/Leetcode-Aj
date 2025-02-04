class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int e=1;
        int ans=nums[0];
        int currsum=ans;
        int prev=nums[0];
        while(e<n){
            if(nums[e]>prev){
                prev=nums[e];
                currsum+=nums[e];
                e++;
            }
            else{
                prev=nums[e];
                currsum=nums[e];
                e++;
            }
            ans=max(ans,currsum);
        }
        return ans;
    }

};