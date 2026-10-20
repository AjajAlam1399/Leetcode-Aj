class Solution {
    public boolean canJump(int[] nums) {
        int n=nums.length;
        int curr=nums[0];
        int maxJump=nums[0];

        if(n==1) return  true;
        if(curr==0) return false;

        for(int i=1;i<n;i++){
            if(i==n-1) return true;
            maxJump=Math.max(maxJump,nums[i]+i);
            if(curr<=i){
                if(maxJump>i){
                    curr=maxJump;
                }
                else{
                    return false;
                }
            }
        }

        return true;
    }
}