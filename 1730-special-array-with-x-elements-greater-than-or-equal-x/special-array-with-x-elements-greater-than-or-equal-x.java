class Solution {
    public int specialArray(int[] nums) {
        // Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            int numRight=nums.length-i;
            int cnt=0;
            for(int j=0;j<nums.length;j++){
                if(nums[j]>=numRight)cnt++;
            }
            if(cnt==numRight)return cnt;
        }
        return -1;
    }
}