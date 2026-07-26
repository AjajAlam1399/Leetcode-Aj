class Solution {
    public void nextPermutation(int[] nums) {
        
        int n = nums.length;
        int ind = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            int i=0;
            int j = n-1;

            while(i<j){
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
            return ;
        }
        int nextSmallestInd = ind+1;

        for(int i = ind+1;i<n;i++){
            if( nums[i]< nums[nextSmallestInd] && nums[i]>nums[ind] ){
                nextSmallestInd = i;
            }
        }

        int temp=nums[ind];
        nums[ind]= nums[nextSmallestInd];
        nums[nextSmallestInd] = temp;

        Arrays.sort(nums, ind+1 , n);

    }
}