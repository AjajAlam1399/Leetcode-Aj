class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {

        int totalsum=0;
        int n=nums.length;

        for(int val:nums){
            totalsum+=val;
        }

        int ans[]=new int[n];
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            int val1=nums[i]*(i+1)-sum;
            int val2=totalsum-sum-nums[i]*(n-1-i);
            ans[i]=val1+val2;
        }
        return ans;
    }
}