class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(nums[i]%3==0)continue;
            else if((nums[i]+1)%3==0 ||(nums[i]-1)%3==0)ans++;
            else if((nums[i]+2)%3==0 ||(nums[i]-2)%3==0)ans+=2;
        }
        return ans;
    }
};