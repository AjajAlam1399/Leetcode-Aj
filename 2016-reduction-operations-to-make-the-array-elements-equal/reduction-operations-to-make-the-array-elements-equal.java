class Solution {
    public int reductionOperations(int[] nums) {
        int n=nums.length;
        long ans=0;

        int s=0;

        Arrays.sort(nums);

        while(s<n){
            while(s+1<n && nums[s]==nums[s+1]){
                s++;
            }
            if(n-1-s>0){
                ans+=n-1-s;
            }
            s++;
        }

        return (int)ans;
    }
}