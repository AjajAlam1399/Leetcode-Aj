class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int m=maxSumSubarr(nums);
        int n=abs(minSumSubarr(nums));
        return max(n,m);
    }
    int maxSumSubarr(vector<int>&nums){
        int sum=0;
        int ans=0;

        int ind=0,n=nums.size();

        while(ind<n){
            sum+=nums[ind];
        
            if(sum<0){
                sum=0;
            }

            if(sum>ans){
                ans=sum;
            }
            ind++;
        }
        return ans;
    }

    int minSumSubarr(vector<int>&nums){
        int sum=0;
        int ans=0;

        int ind=0,n=nums.size();

        while(ind<n){
            sum+=nums[ind];
        
            if(sum>0){
                sum=0;
            }

            if(sum<ans){
                ans=sum;
            }
            ind++;
        }
        return ans;
    }
};