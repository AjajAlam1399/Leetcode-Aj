class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        long totalsum=0;
        int n=nums.size();

        for(auto val:nums){
            totalsum+=val;
        }

        vector<int>ans;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int val1=nums[i]*(i+1)-sum;
            int val2=totalsum-sum-nums[i]*(n-1-i);
            ans.push_back(val1+val2);
        }
        return ans;
    }
};