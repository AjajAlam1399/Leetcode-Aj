class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        long ans=0;
        int start=0,minstart=0,maxstart=0;
        boolean minf=false,maxf=false;
        int n=nums.length;

        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK){
                minf=false;
                maxf=false;
                start=i+1;
            }
            else{
                if(nums[i]==minK){
                    minf=true;
                    minstart=i;
                }
                if(nums[i]==maxK){
                    maxf=true;
                    maxstart=i;
                }
            }
            if(minf && maxf){
                ans+=Math.min(minstart,maxstart)-start+1;
            }
        }
        return ans;
    }
}