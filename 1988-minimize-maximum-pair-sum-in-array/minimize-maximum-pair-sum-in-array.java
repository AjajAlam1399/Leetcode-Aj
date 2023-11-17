class Solution {
    public int minPairSum(int[] nums) {
        if(nums.length==2){
            return nums[0]+nums[1];
        }

        int n=nums.length;

        Arrays.sort(nums);
        int l=nums[0]+nums[1];
        int h=nums[n-1]+nums[n-2];

        int ans=h;

        Solution sl=new Solution();

        while(l<h){
            int mid=(l+h)/2;
            if(sl.fun(nums,mid)){
                ans=Math.min(ans,mid);
                h=mid;
            }
            else{
                l=mid+1;
            }

        }

        return ans;
    }
    private  boolean fun(int nums[],int mid){
        int s=0;
        int e=nums.length-1;

        while(s<=e){
            if(nums[s]+nums[e]<=mid){
                s++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
}