class Solution {
    public int missingNumber(int[] nums) {
        int n=nums.length;

        for(int i=0;i<n;i++){
            if(nums[i]==i){
                continue;
            }
            else{
                while(nums[i]<n && nums[i]!=i){
                    int temp=nums[i];
                    nums[i]=nums[nums[i]];
                    nums[temp]=temp;
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
}