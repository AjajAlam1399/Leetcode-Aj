class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;

        for(int i=0;i<n;i++){
            if(nums[i]==i+1){
                continue;
            }
            while(nums[i]!=i+1){
                int temp = nums[i];
                int next = nums[nums[i]-1];
                if(nums[i]==next)return nums[i];
                nums[nums[i]-1] = nums[i];
                nums[i] = next;
            }
        }

        return -1;
    }
}