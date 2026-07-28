class Solution {
    public int reversePairs(int[] nums) {
        return mergeSort(0,nums.length-1,nums);
    }

    int mergeSort(int s, int e , int [] nums){

        while(s<e){
            int mid = (s+e)/2;
            int ans = 0;
            ans+= mergeSort(s,mid,nums);
            ans+= mergeSort(mid+1,e,nums);
            ans+= merge(s,mid,e,nums);
            return ans;
        }

        return 0;
    }

    int merge(int s, int mid ,int e ,int []nums){
        int n=nums.length;
        int[] temp  =new int[n];
        
        int i=s, j=mid+1;
        int k = s;

        int ans = 0;

        while(i<=mid && j<=e){
            if((long)nums[i]>(long)2*nums[j]){
                ans+=mid-i+1;
                j++;
            }
            else{
                i++;
            }
        }
        i=s;
        j=mid+1;

        while(i<=mid && j<=e){
            if(nums[i]<=nums[j]){
                temp[k++]=nums[i++];
            }
            else{
                temp[k++]=nums[j++];
            }
        }


        while(i<=mid){
            temp[k++]=nums[i++];
        }

        while(j<=e){
            temp[k++]=nums[j++];
        }

        for(int l=s;l<=e;l++){
            nums[l]=temp[l];
        }
        return ans;
    }
}