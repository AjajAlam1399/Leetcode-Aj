class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            else{
                while(nums[i]<n && nums[i]!=i){
                    swap(nums[i],nums[nums[i]]);
                }
            }
        }
        int ans=n;

        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};