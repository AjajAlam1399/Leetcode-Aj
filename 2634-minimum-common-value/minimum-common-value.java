class Solution {
    public int getCommon(int[] nums1, int[] nums2) {
        int ans=-1;
        for(int i=0;i<nums2.length;i++ ){
            if(fun(nums1,nums2[i])){
                ans=nums2[i];
                break;
            }
        }

        return ans;
    }
    boolean fun(int nums[],int val){
        int s=0,e=nums.length-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==val){
                return true;
            }
            else if(nums[mid]>val){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }

        return false;
    }
}