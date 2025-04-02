class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size();
        vector<int>vec(n,-1);
        int rightM=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            vec[i]=rightM;
            rightM=min(rightM,nums[i]);
        }
        int ans=0;
        int leftM=nums[0];
        for(int i=1;i<=n-2;i++){
            if(nums[i]>leftM && nums[i]<vec[i]){
                ans+=2;
            }
            else if(nums[i]>nums[i-1] && nums[i+1]>nums[i]){
                ans+=1;
            }
            leftM=max(leftM,nums[i]);
        }
        return ans;
    }
};